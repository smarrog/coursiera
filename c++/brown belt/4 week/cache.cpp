#include "Common.h"

#include <list>
#include <unordered_map>
#include <mutex>

using namespace std;

using BookPtr = ICache::BookPtr;

class LruCache : public ICache {
public:
    using CacheList = std::list<BookPtr>;
    using CacheListIt = CacheList::iterator;

    LruCache(std::shared_ptr<IBooksUnpacker> unpacker, const Settings& settings);
    BookPtr GetBook(const std::string& bookName) override;
private:
    std::mutex _m;
    std::shared_ptr<IBooksUnpacker> _unpacker;
    const Settings& _settings;
    CacheList _books;
    std::unordered_map<std::string, CacheListIt> _iterators;
    size_t _size;

    BookPtr GetBookFromCache(const CacheListIt& it);
    BookPtr GetBookNotInCache(const std::string& bookName);
    BookPtr Add(BookPtr bookPtr);
    void Remove(const CacheListIt& it);
    void checkSize();
};

LruCache::LruCache(std::shared_ptr<IBooksUnpacker> unpacker, const Settings& settings)
    : _settings(settings)
    , _unpacker(std::move(unpacker))
    , _size(0) { }

BookPtr LruCache::GetBook(const std::string& bookName) {
    _m.lock();
    const auto& it = _iterators.find(bookName);
    auto result = it == _iterators.end() ? GetBookNotInCache(bookName) : GetBookFromCache(it->second);
    _m.unlock();
    return std::move(result);
}

BookPtr LruCache::GetBookFromCache(const CacheListIt& it) {
    if (it == _books.begin()) {
        return *it;
    }
    auto bookPtr = *it;
    Remove(it);
    return Add(std::move(bookPtr));
}

BookPtr LruCache::GetBookNotInCache(const std::string& bookName) {
    return Add(_unpacker->UnpackBook(bookName));
}

BookPtr LruCache::Add(BookPtr bookPtr) {
    checkSize();
    auto reqSize = bookPtr->GetContent().size();
    if (reqSize > _settings.max_memory) {
        return std::move(bookPtr);
    }
    _size += reqSize;
    _books.push_front(std::move(bookPtr));
    _iterators[_books.begin()->get()->GetName()] = _books.begin();
    checkSize();
    return *_books.begin();
}

void LruCache::Remove(const CacheListIt& it) {
    _size -= it->get()->GetContent().size();
    _iterators.erase(it->get()->GetName());
    _books.erase(it);
}

void LruCache::checkSize() {
    while (_size > _settings.max_memory && _books.begin() != _books.end()) {
        Remove(std::prev(_books.end()));
    }
}

std::unique_ptr<ICache> MakeCache(std::shared_ptr<IBooksUnpacker> unpacker, const ICache::Settings& settings) {
    return std::make_unique<LruCache>(std::move(unpacker), settings);
}
