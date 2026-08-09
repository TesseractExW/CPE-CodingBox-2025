#include <iostream>
#include <utility>
#include <queue>

// priority queue, min-max heap, greedy
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    std::cin >> n;
    std::priority_queue<std::pair<int, int>> _pqueue;

    for (int i = 0; i < n; i++) {
        int score, count;
        std::cin >> score >> count;

        _pqueue.emplace(score, count);
    }

    int r;
    std::cin >> r;

    for (int i = 0; i < r; i++) {
        int totalCount;
        std::cin >> totalCount;

        int totalScore = 0;
        while (totalCount > 0) {
            auto [score, count] = _pqueue.top();
            _pqueue.pop();

            int commonCount = std::min(count, totalCount);
            totalScore += commonCount * score;
            totalCount -= commonCount;
            count -= commonCount;

            if (count > 0) {
                _pqueue.emplace(score, count);
            }
        }

        std::cout << totalScore << '\n';
    }

    return 0;
}