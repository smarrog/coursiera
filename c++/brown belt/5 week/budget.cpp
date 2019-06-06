#include <vector>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <unordered_map>

using DaysRange = std::pair<size_t, size_t>;

class BudgetManager {
public:
    void earn(DaysRange timeRange, double value) {
        double valuePerDay = value / (timeRange.second - timeRange.first + 1);
        for (auto day = timeRange.first; day <= timeRange.second; day++) {
            _budget[day] += valuePerDay;
        }
    }

    double computeIncome(DaysRange timeRange) const {
        auto sum = 0.0;
        for (auto day = timeRange.first; day <= timeRange.second; day++) {
            auto it = _budget.find(day);
            if (it != _budget.end()) {
                sum += it->second;
            }
        }
        return sum;
    }

    void payTax(DaysRange timeRange) {
        for (auto day = timeRange.first; day <= timeRange.second; day++) {
            auto it = _budget.find(day);
            if (it != _budget.end()) {
                it->second *= 0.87;
            }
        }
    }
private:
    std::unordered_map<size_t, double> _budget;
};

std::tm ReadDate(std::istream& input) {
    std::tm t;

    t.tm_sec   = 0;
    t.tm_min   = 0;
    t.tm_hour  = 0;
    t.tm_isdst = 0;

    input >> t.tm_year;
    input.ignore();
    input >> t.tm_mon;
    input.ignore();
    input >> t.tm_mday;

    t.tm_year -= 1900;
    t.tm_mon--;

    return t;
}

DaysRange ReadTimeRange(std::istream& input) {
    std::tm from = ReadDate(input);
    std::tm to = ReadDate(input);
    return { std::mktime(&from) / 86400, std::mktime(&to) / 86400 };
}

int main() {
    //std::ifstream input("input.txt");
    std::istream& input = std::cin;

    std::cout.setf(std::ios::fixed);

    int n;
    input >> n;
    std::string command;
    BudgetManager bm;
    while (n--) {
        input >> command;
        if (command == "ComputeIncome") {
            std::cout << bm.computeIncome(ReadTimeRange(input)) << '\n';
        } else if (command == "Earn") {
            auto timeRange = ReadTimeRange(input);
            int v;
            input >> v;
            bm.earn(timeRange, static_cast<double>(v));
        } else if (command == "PayTax") {
            bm.payTax(ReadTimeRange(input));
        }
    }

    return 0;
}