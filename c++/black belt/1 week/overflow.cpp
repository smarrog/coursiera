#include <iostream>

int main() {
    std::int64_t a;
    std::int64_t b;
    std::cin >> a;
    std::cin >> b;

    if ((double(a) + double(b)) > INT64_MAX || (double(a) + double(b)) < INT64_MIN) {
        std::cout << "Overflow!";
    } else {
        std::cout << a + b;
    }

    return 0;
}
