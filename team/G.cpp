#include <iostream>

// fast ceiling
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int l, k, m, n;
    std::cin >> l >> k;
    std::cin >> m >> n;

    int total = 0;
    for (int i = 0; i < m * n; i++) {
        int height;
        std::cin >> height;

        total += std::max(0, height -  k);
    }

    std::cout << (total + l - 1) / l;
    return 0;
}