#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <set>

class RouteManager {
public:
    void AddRoute(int start, int finish) {
        _routes[start].insert(finish);
        _routes[finish].insert(start);
    }

    int FindNearestFinish(int start, int finish) const {
        int result = abs(start - finish);
        auto it = _routes.find(start);
        if (it == _routes.end()) {
            return result;
        }
        const auto finishIt = it->second.lower_bound(finish);
        if (finishIt != it->second.end()) {
            result = std::min(result, std::abs(finish - *finishIt));
        }
        if (finishIt != it->second.begin()) {
            result = std::min(result, std::abs(finish - *std::prev(finishIt)));
        }
        return result;
    }
private:
    std::map<int, std::set<int>> _routes;
};


int main() {
    RouteManager routes;
    std::istream& input = std::cin;

    int query_count;
    input >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        std::string query_type;
        input >> query_type;
        int start, finish;
        input >> start >> finish;
        if (query_type == "ADD") {
            routes.AddRoute(start, finish);
        } else if (query_type == "GO") {
            std::cout << routes.FindNearestFinish(start, finish) << "\n";
        }
    }

    return 0;
}
