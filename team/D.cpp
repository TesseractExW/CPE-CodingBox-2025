#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

// greedy, sorting
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::int64_t m;
    std::size_t n;
    std::cin >> m >> n;

    std::vector<std::int64_t> cnts(n);
    for (std::int64_t &cnt : cnts) {
        std::cin >> cnt; 
    }

    std::sort(cnts.begin(), cnts.end(), std::greater<int>());

    for (std::size_t i = 0; i < n; i++) {
        m -= cnts[i];

        if (m <= 0) {
            std::cout << i + 1; 
            return 0;
        }
    }

    std::cout << -1;
    return 0;
}
