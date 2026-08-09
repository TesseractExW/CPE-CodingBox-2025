#include <iostream>
#include <cstdint>

// math, prefix sum
constexpr long long mod = (long long)1e9 + 7;

long long pmodulo(long long n) {
    return (n % mod + mod) % mod;
}

long long summation(long long n, long long skip) {
    long long m = n / skip;
    m = pmodulo(m);

    return pmodulo(pmodulo(m * (m + 1) / 2) * skip);
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    long long n;
    std::cin >> n;

    long long result = 0;
    result = pmodulo(result + summation(n, 1));
    result = pmodulo(result - summation(n, 7));
    result = pmodulo(result  + 2 * summation(n, 11));
    result = pmodulo(result - 2 * summation(n, 77));

    std::cout << result;
    return 0;
}