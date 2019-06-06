#include <string>
#include <vector>

template <typename Iterator>
class Page {
public:
    Page(Iterator begin, Iterator end)
            : _begin(begin)
            , _end (end) {

    }

    Iterator begin() const {
        return _begin;
    }

    Iterator end() const {
        return _end;
    }

    size_t size() const {
        return end() - begin();
    }
private:
    Iterator _begin;
    Iterator _end;
};

template <typename Iterator>
class Paginator {
public:
    Paginator(Iterator begin, Iterator end, size_t pageSize)
            : _begin(begin)
            , _end(end)
            , _pageSize(pageSize) {
        auto current = _begin;
        while (current != _end) {
            auto currentPageSize = std::min(pageSize, (size_t) (_end - current));
            auto pageEnd = current + currentPageSize;
            _pages.push_back({ current, pageEnd });
            current = pageEnd;
        }
    }

    auto begin() const {
        return _pages.begin();
    }

    auto end() const {
        return _pages.end();
    }

    size_t size() const {
        return end() - begin();
    }
private:
    Iterator _begin;
    Iterator _end;
    size_t _pageSize;
    std::vector<Page<Iterator>> _pages;
};

template <typename C>
auto Paginate(C& c, size_t page_size) {
    return Paginator(c.begin(), c.end(), page_size);
}