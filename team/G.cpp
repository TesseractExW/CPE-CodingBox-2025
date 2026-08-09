#include <iostream>
#include <cstdint>

// fast ceiling
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::uint64_t l, k, m, n;
    std::cin >> l >> k;
    std::cin >> m >> n;

    std::uint64_t total = 0;
    for (std::uint64_t i = 0; i < m * n; i++) {
        std::uint64_t height;
        std::cin >> height;

        total += std::max(0ULL, height -  k);
    }

    std::cout << (total + l - 1) / l;
    return 0;
}