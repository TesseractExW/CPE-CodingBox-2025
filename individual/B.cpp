#include <iostream>
#include <iomanip>
#include <cmath>

// math
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::size_t n, d;
        std::cin >> n >> d;

        std::cout << 0.25l * d * d * (std::acosl(-1) - 0.5l * n * std::sinl(2 * std::acosl(-1) / n)) << '\n';
    }
    return 0;
}