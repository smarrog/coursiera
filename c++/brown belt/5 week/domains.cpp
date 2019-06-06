#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

#include "test_runner.h"

bool IsSubdomain(std::string_view subdomain, std::string_view domain) {
    if (domain.size() < subdomain.size() || (domain.size() > subdomain.size() && domain[subdomain.size()] != '.')) {
        return false;
    }
    return domain.substr(0, subdomain.size()) == subdomain;
}


std::vector<std::string> ReadDomains(std::istream& input) {
    size_t count;
    input >> count;
    while (std::isspace(input.peek())) {
        input.ignore();
    }
    std::vector<std::string> domains;
    while (count--) {
        std::string domain;
        std::getline(input, domain);
        domains.emplace_back(std::move(domain));
    }
    return domains;
}

bool checkDomain(std::string domain, const std::vector<std::string>& bannedDomains) {
    if (bannedDomains.empty()) {
        return true;
    }
    std::reverse(domain.begin(), domain.end());
    auto upperBound = std::upper_bound(bannedDomains.begin(), bannedDomains.end(), domain);
    if (upperBound != bannedDomains.begin() && IsSubdomain(*std::prev(upperBound), domain)) {
        return false;
    }
    auto pos = domain.find('.');
    if (pos == std::string::npos) {
        return true;
    }
    auto lowerBoundDomain(domain);
    lowerBoundDomain.resize(pos);
    auto lowerBound = std::lower_bound(bannedDomains.begin(), bannedDomains.end(), lowerBoundDomain);
    for (auto it = lowerBound; it != upperBound; it++) {
        if (IsSubdomain(*it, domain)) {
            return false;
        }
    }
    return true;
}

void prepareAndCheck(std::istream& is, std::ostream& os) {
    const std::vector<std::string> reversed_banned_domains = [&is](){
        std::vector<std::string> domains = ReadDomains(is);
        for (auto& domain : domains) {
            std::reverse(domain.begin(), domain.end());
        }
        std::sort(domains.begin(), domains.end());
        return std::move(domains);
    }();
    auto domains = ReadDomains(is);
    for (auto& domain : domains) {
        if (checkDomain(std::move(domain), reversed_banned_domains)) {
            os << "Good";
        } else {
            os << "Bad";
        }
        os << "\n";
    }
}

void TestParse() {
    std::istringstream is(
            R"(4
ya.ru
maps.me
m.ya.ru
com
7
ya.ru
ya.com
m.maps.me
moscow.m.ya.ru
maps.com
maps.ru
ya.ya
)");
    std::ostringstream os;
    prepareAndCheck(is, os);

    ASSERT_EQUAL(os.str(),
                 R"(Bad
Bad
Bad
Bad
Bad
Good
Good
)");
}

void TestCheckSubdomain() {
    ASSERT(IsSubdomain("ur", "ur"));
    ASSERT(IsSubdomain("ur.ya", "ur.ya"));
    ASSERT(IsSubdomain("ur", "ur.ya"));
    ASSERT(!IsSubdomain("ur", "uray"));
    ASSERT(!IsSubdomain("ur", "ay.ur"));
    ASSERT(!IsSubdomain("ur", "moc"));
}

#define ASSERT_DOMAIN(domain, bannedDomains, boolValue) ASSERT_EQUAL(checkDomain(domain, bannedDomains), boolValue);
#define GOOD_DOMAIN(domain, bannedDomains) ASSERT_DOMAIN(domain, bannedDomains, true);
#define BAD_DOMAIN(domain, bannedDomains) ASSERT_DOMAIN(domain, bannedDomains, false);

void TestCheck() {
    const std::vector<std::string> bannedDomains = [](){
        std::vector<std::string> domains{
            "ya.ru",
            "maps.me",
            "m.ya.ru",
            "c.m.ya.ru",
            "b.c.m.ya.ru",
            "a.b.c.m.ya.ru",
            "coa",
            "coz",
            "com"
        };
        for (auto& domain : domains) {
            std::reverse(domain.begin(), domain.end());
        }
        std::sort(domains.begin(), domains.end());
        return domains;
    }();
    BAD_DOMAIN("ya.ru", bannedDomains);
    BAD_DOMAIN("ya.ya.ru", bannedDomains);
    BAD_DOMAIN("aa.ya.ru", bannedDomains);
    BAD_DOMAIN("ya.com", bannedDomains);
    BAD_DOMAIN("m.maps.me", bannedDomains);
    BAD_DOMAIN("moscow.m.ya.ru", bannedDomains);
    BAD_DOMAIN("maps.com", bannedDomains);
    BAD_DOMAIN("m.ya.ru", bannedDomains);
    BAD_DOMAIN("am.ya.ru", bannedDomains);
    BAD_DOMAIN("as.b.c.m.ya.ru", bannedDomains);
    BAD_DOMAIN("a.bd.c.m.ya.ru", bannedDomains);

    GOOD_DOMAIN("a.ru", bannedDomains);
    GOOD_DOMAIN("yar.u", bannedDomains);
    GOOD_DOMAIN("maps.ru", bannedDomains);
    GOOD_DOMAIN("ya.ya", bannedDomains);
    GOOD_DOMAIN("yya.ru", bannedDomains);
    GOOD_DOMAIN("yaru", bannedDomains);
}

void TestEmpty() {
    const std::vector<std::string> bannedDomains{};
    GOOD_DOMAIN("ya.ru", bannedDomains);
}

void TestSingleBan() {
    const std::vector<std::string> bannedDomains{"ur"};
    BAD_DOMAIN("ya.ru", bannedDomains);
    BAD_DOMAIN("ru", bannedDomains);
    GOOD_DOMAIN("ya.com", bannedDomains);
    GOOD_DOMAIN("ur", bannedDomains);
    GOOD_DOMAIN("aa", bannedDomains);
    GOOD_DOMAIN("zz", bannedDomains);
}

void TestDuplicate() {
    const std::vector<std::string> bannedDomains{"ur", "ur", "ur"};
    BAD_DOMAIN("ya.ru", bannedDomains);
    BAD_DOMAIN("ru", bannedDomains);
    GOOD_DOMAIN("ya.com", bannedDomains);
    GOOD_DOMAIN("ur", bannedDomains);
    GOOD_DOMAIN("aa", bannedDomains);
    GOOD_DOMAIN("zz", bannedDomains);
}

int main() {
    /*TestRunner tr;
    RUN_TEST(tr, TestCheck);
    RUN_TEST(tr, TestEmpty);
    RUN_TEST(tr, TestSingleBan);
    RUN_TEST(tr, TestDuplicate);
    RUN_TEST(tr, TestCheckSubdomain);
    RUN_TEST(tr, TestParse);*/

    prepareAndCheck(std::cin, std::cout);

    return 0;
}
