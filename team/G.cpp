#include <iostream>

// fast ceiling
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::size_t l, k, m, n;
    std::cin >> l >> k;
    std::cin >> m >> n;

    std::size_t total = 0;
    for (std::size_t i = 0; i < m * n; i++) {
        std::size_t height;
        std::cin >> height;

        total += std::max(0uz, height -  k);
    }

    std::cout << (total + l - 1) / l;
    return 0;
}