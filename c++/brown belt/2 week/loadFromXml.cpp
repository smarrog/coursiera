#include "xml.h"

#include <vector>

struct Spending {
    string category;
    int amount;
};

std::vector<Spending> LoadFromXml(std::istream& input) {
    Document doc = Load(input);
    std::vector<Spending> result;
    for (const auto& node : doc.GetRoot().Children()) {
        result.push_back({
            node.AttributeValue<string>("category"),
            node.AttributeValue<int>("amount")
        });
    }
    return result;
}