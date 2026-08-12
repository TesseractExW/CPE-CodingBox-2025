#include <cstdint>
#include <iostream>

// math, unsigned int
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::uint64_t first, best = 0;
    std::cin >> first;
    best = first;

    std::uint64_t crr;
    while (std::cin >> crr && crr > 0) {
        best = std::max(best, crr);
    }

    std::cout << (first < best ? best - first : first - best);

    return 0;
}
