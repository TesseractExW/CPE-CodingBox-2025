#include <iostream>
#include <vector>
#include <iomanip>

// dynamics programming, optimization
constexpr int INF = (int)1e9;

int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::size_t n, h;
    std::cin >> n >> h;

    std::vector<int> dp(h + 1, -INF);
    dp[0] = 0;

    for (std::size_t i = 0; i < n; i++) {
        std::vector<int> hours(4);

        for (int &hour : hours) {
            std::cin >> hour;
        }

        for (std::size_t j = h + 1; j-- > 0; ) {
            for (int k = 0; k < 4; k++) {
                if (hours[k] <= j) {
                    dp[j] = std::max(dp[j], 4 - k + dp[j - hours[k]]);
                }
            }
        }
    }

    std::cout << std::fixed << std::setprecision(10);
    std::cout << 1.0l * (*std::max_element(dp.begin(), dp.end())) / n;
    return 0;
}
