#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// graph theory, topological sort, dynamics programming
namespace std {
    template <typename T>
    using matrix = std::vector<std::vector<T>>;
}

int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::size_t n;
    std::cin >> n;

    std::queue<std::size_t> _queue;
    std::matrix<std::size_t> graph(n);
    std::vector<std::size_t> indegres(n, 0), dp(n, 0);

    for (std::size_t i = 0; i < n; i++) {
        std::cin >> indegres[i];

        if (indegres[i] == 0) {
            dp[i] = 1;
            _queue.push(i);
        }

        for (std::size_t j = 0; j < indegres[i]; j++) {
            std::size_t node;
            std::cin >> node;

            graph[--node].push_back(i);
        }
    }

    while (!_queue.empty()) {
        std::size_t front = _queue.front();
        _queue.pop();

        for (std::size_t node : graph[front]) {
            dp[node] = std::max(dp[node], dp[front] + 1);

            if (--indegres[node] == 0) {
                _queue.push(node);
            }
        }
    }

    if (*std::min_element(dp.begin(), dp.end()) == 0) {
        std::cout << -1;
    } else {
        std::cout << *std::max_element(dp.begin(), dp.end());
    }

    return 0;
}