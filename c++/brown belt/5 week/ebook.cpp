#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <map>

class ReadingManager {
public:
    ReadingManager()
        : _usersPage(MAX_USER_COUNT + 1, -1),
          _pageUsers(MAX_PAGE_COUNT + 1, 0) {}

    void Read(int userId, int page) {
        UpdatePageRange(_usersPage[userId] + 1, page + 1);
        _usersPage[userId] = page;
    }

    double Cheer(int userId) const {
        const int page = _usersPage[userId];
        if (page == -1) {
            return 0;
        }
        const int totalUsers = _pageUsers[0];
        if (totalUsers == 1) {
            return 1;
        }
        return (totalUsers - _pageUsers[page]) * 1.0 / (totalUsers - 1);
    }

private:
    static const int MAX_USER_COUNT = 100'000;
    static const int MAX_PAGE_COUNT = 1'000;

    std::vector<int> _usersPage;
    std::vector<int> _pageUsers;

    void UpdatePageRange(int lhs, int rhs) {
        for (int i = lhs; i < rhs; ++i) {
            ++_pageUsers[i];
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    std::cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        std::string query_type;
        std::cin >> query_type;
        int user_id;
        std::cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            std::cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            std::cout << std::setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }

    return 0;
}
