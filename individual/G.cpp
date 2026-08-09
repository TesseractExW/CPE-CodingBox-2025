#include <iostream>
#include <cstdint>

// math, prefix sum
constexpr std::int64_t mod = (std::int64_t)1e9 + 7;

std::int64_t pmodulo(std::int64_t n) {
    return (n % mod + mod) % mod;
}

std::int64_t summation(std::int64_t n, std::int64_t skip) {
    std::int64_t m = n / skip;
    m = pmodulo(m);

    return pmodulo(pmodulo(m * (m + 1) / 2) * skip);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::int64_t n;
    std::cin >> n;

    std::int64_t result = 0;
    result = pmodulo(result + summation(n, 1));
    result = pmodulo(result - summation(n, 7));
    result = pmodulo(result  + 2 * summation(n, 11));
    result = pmodulo(result - 2 * summation(n, 77));

    std::cout << result;
    return 0;
}