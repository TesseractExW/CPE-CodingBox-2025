#include <iostream>
#include <vector>
#include <algorithm>

// greedy, sorting
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int m, n;
    std::cin >> m >> n;

    std::vector<int> cnts(n);
    for (int &cnt : cnts) {
        std::cin >> cnt; 
    }

    std::sort(cnts.begin(), cnts.end(), std::greater<int>());
     
    for (int i = 0; i < n; i++) {
        m -= cnts[i];
         
        if (m <= 0) {
            std::cout << i + 1; 
            return 0;
        }
    }
     
    std::cout << -1;
    return 0;
}