template <typename It>
void print(It rangeStart, It rangeEnd, const std::string& description) {
    std::cout << "Median age " << description << " = " << ComputeMedianAge(rangeStart, rangeEnd) << "\n";
}

void PrintStats(std::vector<Person> persons) {
    auto femalesEnd = std::partition(persons.begin(), persons.end(), [](const Person& person){
        return person.gender == Gender::FEMALE;
    });
    auto employedFemalesEnd = std::partition(persons.begin(),femalesEnd, [](const Person& person){
        return person.is_employed;
    });
    auto employedMalesEnd = std::partition(femalesEnd, persons.end(), [](const Person& person){
        return person.is_employed;
    });

    print(persons.begin(), persons.end(), "");
    print(persons.begin(), femalesEnd, "for females");
    print(femalesEnd, persons.end(), "for males");
    print(persons.begin(), employedFemalesEnd, "for employed females");
    print(employedFemalesEnd, femalesEnd, "for unemployed females");
    print(femalesEnd, employedMalesEnd, "for employed males");
    print(employedMalesEnd, persons.end(), "for unemployed males");
}