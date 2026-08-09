#include <iostream>
#include <cstdint>

// modulo, division
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::uint64_t a, b;
    std::cin >> a >> b;

    std::uint64_t _a = 0;
    std::uint64_t _b = 0;

    while (a > 0) {
        _a += a % 10;
        a /= 10;
    }
    while (b > 0) {
        _b += b % 10;
        b /= 10;
    }
     
    std::cout << (_a == _b ? "Yes" : "No");
    return 0;
}