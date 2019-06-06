#include "json.h"

#include <vector>

struct Spending {
    string category;
    int amount;
};

std::vector<Spending> LoadFromJson(std::istream &input) {
    Document doc = Load(input);
    std::vector<Spending> result;
    for (const auto& node : doc.GetRoot().AsArray()) {
        auto &m = node.AsMap();
        result.push_back({
            m.at("category").AsString(),
            m.at("amount").AsInt()
        });
    }
    return result;
}