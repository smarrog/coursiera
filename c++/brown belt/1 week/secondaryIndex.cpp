#include "test_runner.h"

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <cmath>
#include <unordered_set>

using namespace std;

struct Record {
    std::string id;
    std::string title;
    std::string user;
    int timestamp;
    int karma;

    bool operator == (const Record& other) const {
        return id == other.id && title == other.title && user == other.user && timestamp == other.timestamp && karma == other.karma;
    }
};

using TimestampMap = std::map<int, std::vector<const Record*>>;
using KarmaMap = std::map<int, std::vector<const Record*>>;
using UserMap = std::map<std::string, std::vector<const Record*>>;

struct DatabaseElem {
    DatabaseElem(Record record)
            : record(std::move(record)) {

    }

    Record record;
    int timestampIndex;
    int karmaIndex;
    int userIndex;
};

// Реализуйте этот класс
class Database {
public:
    bool Put(Record record) {
        auto&& [it, result] = _storage.emplace(record.id, std::move(record));
        if (result) {
            auto& elem = it->second;
            elem.timestampIndex = addToIndexMap(_timestampMap, elem.record.timestamp, &elem.record);
            elem.karmaIndex = addToIndexMap(_karmaMap, elem.record.karma, &elem.record);
            elem.userIndex = addToIndexMap(_userMap, elem.record.user, &elem.record);
        }
        return result;
    }

    const Record* GetById(const string &id) const {
        auto it = _storage.find(id);
        return it == _storage.end() ? nullptr : &it->second.record;
    }

    bool Erase(const string &id) {
        auto it = _storage.find(id);
        if (it == _storage.end()) {
            return false;
        }
        auto& elem = it->second;
        removeFromIndexMap(_timestampMap, elem.record.timestamp, elem.timestampIndex);
        removeFromIndexMap(_karmaMap, elem.record.karma, elem.karmaIndex);
        removeFromIndexMap(_userMap, elem.record.user, elem.userIndex);
        _storage.erase(it);
        return true;
    }

    template<typename Callback>
    void RangeByTimestamp(int low, int high, Callback callback) const {
        rangeByKeys(_timestampMap, low, high, callback);
    }

    template<typename Callback>
    void RangeByKarma(int low, int high, Callback callback) const {
        rangeByKeys(_karmaMap, low, high, callback);
    }

    template<typename Callback>
    void AllByUser(const std::string &user, Callback callback) const {
        rangeByKey(_userMap, user, callback);
    }

private:
    std::unordered_map<std::string, DatabaseElem> _storage;
    TimestampMap _timestampMap;
    KarmaMap _karmaMap;
    UserMap _userMap;

    template <typename M, typename K>
    int addToIndexMap(M& m, const K& key, const Record* recordPt) {
        auto& v = m[key];
        v.push_back(recordPt);
        return v.size() - 1;
    }

    template <typename M, typename K>
    void removeFromIndexMap(M& m, const K& key, int index) {
        m[key][index] = nullptr;
    }

    template<typename M, typename Callback>
    void rangeByKeys(const M& m, int low, int high, Callback callback) const {
        for (auto value = low; value <= high; value++) {
            if (!rangeByKey(m, value, callback))
                return;
        }
    }

    template<typename M, typename K, typename Callback>
    bool rangeByKey(const M &m, const K &key, Callback callback) const {
        auto it = m.find(key);
        if (it == m.end()) {
            return true;
        }
        for (auto pt : it->second) {
            if (pt != nullptr && !callback(*pt)) {
                return false;
            }
        }
        return true;
    }
};