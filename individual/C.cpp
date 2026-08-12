#include <iostream>
#include <vector>
#include <bitset>
#include <string>

// bit manipulation, string manipulation, bitwise
constexpr std::size_t MAX_2N   = (std::size_t)2e6;
constexpr std::size_t MAX_CHAR = 256;

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::size_t n, q;
    std::cin >> n >> q;

    std::string baseString; 
    std::cin >> baseString;
    baseString += baseString;

    std::vector<std::bitset<MAX_2N>> charPosition(MAX_CHAR);
    for (std::size_t i = 0; i < 2 * n; i++) {
        charPosition[baseString[i]][i] = true;
    }

    std::bitset<MAX_2N> validStart;
    for (std::size_t i = 0; i < n; i++) {
        validStart[i] = true;
    }

    for (std::size_t i = 0; i < q; i++) {
        std::bitset<MAX_2N> currValidStart = validStart;

        std::size_t m;
        std::cin >> m;
        std::string currString;
        std::cin >> currString;

        for (std::size_t j = 0; j < m; j++) {
            char ch = currString[j];
            if (ch != '*') {
                currValidStart &= (charPosition[ch] >> j);
            }
        }

        std::cout << currValidStart.count();
        for (std::size_t j = 0; j < n; j++) {
            if (currValidStart[j]) {
                std::cout << ' ' << j + 1;
            }
        }
        std::cout << '\n';
    }

    return 0;
}
