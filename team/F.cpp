#include <iostream>
#include <vector>

// dynamics programming, grid, modulo
constexpr long long mod = (long long)(1e9 + 7);

int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::size_t r, c, n;
    std::cin >> r >> c;
    std::cin >> n;

    std::vector<std::vector<long long>> dp(r + 1, std::vector<long long>(c + 1, 0));
    dp[1][1] = 1;

    for (std::size_t i = 0; i < n; i++) {
        std::size_t x, y;
        std::cin >> x >> y;
         
        dp[x][y] = -1;
    }

    for (std::size_t i = 1; i <= r; i++) {
        for (std::size_t j = 1; j <= c; j++) {
            if (dp[i][j] != 0) {
                continue;
            } 

            if (dp[i - 1][j] > 0) {
                (dp[i][j] += dp[i - 1][j]) %= mod;
            }
            if (dp[i][j - 1] > 0) {
                (dp[i][j] += dp[i][j - 1]) %= mod;
            }
        }
    }

    std::cout << std::max(0ll, dp[r][c]);
    return 0;
}