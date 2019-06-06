#include <cstdio>
#include <utility>
#include <list>
#include <vector>
#include <set>

template <typename T>
class PriorityCollection {
public:
    using Id = size_t;

    PriorityCollection() {
        _priorities.emplace_back(std::set<size_t>());
    }

    size_t Add(T object) {
        Id id;
        if (_removed.empty()) {
            id = _values.size();
            _priorities[0].insert(id);
            _values.emplace_back(std::move(object), 0);
        } else {
            id = _removed.front();
            _priorities[0].insert(id);
            _values[id].first = std::move(object);
            _values[id].second = 0;
            _removed.pop_front();
        }
        return id;
    }

    template <typename ObjInputIt, typename IdOutputIt>
    void Add(ObjInputIt rangeBegin, ObjInputIt rangeEnd, IdOutputIt idsBegin) {
        for (auto it = rangeBegin; it != rangeEnd; it++) {
            *idsBegin = Add(std::move(*it));
            idsBegin++;
        }
    }

    bool IsValid(Id id) const {
        return id < _values.size() && _values[id].second >= 0;
    }

    const T& Get(Id id) const {
        return _values[id].first;
    }

    void Promote(Id id) {
        _priorities[_values[id].second].erase(id);
        _values[id].second++;
        if (_priorities.size() == _values[id].second) {
            _priorities.emplace_back(std::set<Id>());
        }
        _priorities[_values[id].second].insert(id);
    }

    std::pair<const T&, int> GetMax() const {
        return _values[*_priorities[getMaxPriority()].rbegin()];
    }

    std::pair<T, int> PopMax() {
        auto priority = getMaxPriority();
        auto id = *_priorities[priority].rbegin();
        _priorities[priority].erase(id);
        _values[id].second = -1;
        return { std::move(_values[id].first), priority };
    }
private:
    std::vector<std::pair<T, int>> _values;
    std::vector<std::set<Id>> _priorities;
    std::list<Id> _removed;

    int getMaxPriority() const {
        for (size_t i = 1; i <= _priorities.size(); i++) {
            if (!_priorities[_priorities.size() - i].empty()) {
                return _priorities.size() - i;
            }
        }
        return -1;
    }
};