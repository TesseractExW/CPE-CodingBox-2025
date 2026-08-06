#include <iostream>
#include <vector>

// dynamics programming, grid, modulo
constexpr int mod = (int)(1e9 + 7);

int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int r, c, n;
    std::cin >> r >> c;
    std::cin >> n;

    std::vector<std::vector<int>> dp(r + 1, std::vector<int>(c + 1, 0));
    dp[1][1] = 1;

    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
         
        dp[x][y] = -1;
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
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

    std::cout << std::max(0, dp[r][c]);
    return 0;
}