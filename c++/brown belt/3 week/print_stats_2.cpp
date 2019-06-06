#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <fstream>

using namespace std;

template <typename Iterator>
class IteratorRange {
public:
    IteratorRange(Iterator begin, Iterator end)
            : first(begin)
            , last(end)
    {
    }

    Iterator begin() const {
        return first;
    }

    Iterator end() const {
        return last;
    }

private:
    Iterator first, last;
};

template <typename Collection>
auto Head(Collection& v, size_t top) {
    return IteratorRange{v.begin(), next(v.begin(), min(top, v.size()))};
}

struct Person {
    string name;
    int age, income;
    bool is_male;
};

vector<Person> ReadPeople(istream& input) {
    int count;
    input >> count;

    vector<Person> result(count);
    for (Person& p : result) {
        char gender;
        input >> p.name >> p.age >> p.income >> gender;
        p.is_male = gender == 'M';
    }

    return result;
}

int main() {
    //std::ifstream input("input.txt");
    std::istream& input = cin;
    std::ostream& output = cout;

    auto people = ReadPeople(input);
    const std::vector<Person> peopleSortedByAge = [&people]{
        auto result(people);
        std::sort(result.begin(), result.end(), [](const Person& lhs, const Person& rhs) {
            return lhs.age < rhs.age;
        });
        return result;
    }();
    const std::vector<Person> peopleSortedByIncome = [&people]{
        auto result(people);
        std::sort(result.begin(), result.end(), [](const Person& lhs, const Person& rhs) {
            return lhs.income > rhs.income;
        });
        return result;
    }();
    const std::pair<const std::string, const std::string> mostPopularNames = [&people]{
        std::vector<Person> males;
        std::vector<Person> females;
        for (const auto& person : people) {
            if (person.is_male) {
                males.push_back(person);
            } else {
                females.push_back(person);
            }
        }
        auto getMostPopularName = [](std::vector<Person> v){
            if (v.empty()) {
                return std::string();
            }
            std::sort(v.begin(), v.end(), [](const Person& lhs, const Person& rhs) {
                return lhs.name < rhs.name;
            });
            const string* most_popular_name = &v[0].name;
            int count = 1;
            for (auto i = v.begin(); i != v.end(); ) {
                auto same_name_end = find_if_not(i, v.end(), [i](const Person& p) {
                    return p.name == i->name;
                });
                auto cur_name_count = std::distance(i, same_name_end);
                if (cur_name_count > count) {
                    count = cur_name_count;
                    most_popular_name = &i->name;
                }
                i = same_name_end;
            }
            return *most_popular_name;
        };

        return make_pair(getMostPopularName(std::move(males)), getMostPopularName(std::move(females)));
    }();

    for (string command; input >> command; ) {
        if (command == "AGE") {
            int adult_age;
            input >> adult_age;
            auto adult_begin = std::lower_bound(begin(peopleSortedByAge), end(peopleSortedByAge), adult_age, [](const Person& lhs, int age) {
                return lhs.age < age;
            });
            output << "There are " << std::distance(adult_begin, end(peopleSortedByAge)) << " adult people for maturity age " << adult_age << '\n';
        } else if (command == "WEALTHY") {
            size_t count;
            input >> count;
            auto head = Head(peopleSortedByIncome, count);
            int total_income = std::accumulate(head.begin(), head.end(), 0, [](int cur, const Person& p) {
                return cur + p.income;
            });
            output << "Top-" << count << " people have total income " << total_income << '\n';
        } else if (command == "POPULAR_NAME") {
            char gender;
            input >> gender;
            const auto& name = (gender == 'M') ? mostPopularNames.first : mostPopularNames.second;
            if (name.empty()) {
                output << "No people of gender " << gender << '\n';
            } else {
                output << "Most popular name among people of gender " << gender << " is " << name << '\n';
            }
        }
    }
}
