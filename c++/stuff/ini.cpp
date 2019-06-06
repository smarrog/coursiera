#include "ini.h"

namespace Ini {
    Section& Document::AddSection(std::string name) {
        return _sections[name];
    }

    const Section& Document::GetSection(const std::string& name) const {
        return _sections.at(name);
    }

    size_t Document::SectionCount() const {
        return _sections.size();
    }

    bool loadKeyValue(std::istream& input, Section* section) {
        std::string line;
        std::getline(input, line);
        auto pos = line.find('=');
        if (pos == std::string::npos) {
            return false;
        }
        section->emplace(line.substr(0, pos), line.substr(pos + 1));
        return true;
    }

    void loadSection(std::istream& input, Document& document) {
        std::string line;
        std::getline(input, line);
        if (line.empty() || line[0] != '[') {
            return;
        }

        auto sectionPt = &document.AddSection(line.substr(1, line.size() - 2));
        auto flag = true;
        while (flag) {
            flag = loadKeyValue(input, sectionPt);
        }
    }

    Document Load(std::istream& input) {
        Document document;
        while (!input.eof()) {
            loadSection(input, document);
        }
        return document;
    }
}

