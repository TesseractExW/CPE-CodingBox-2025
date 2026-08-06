#include <iostream>

// bitwise, boolean
int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        
        bool isAscending = true, isDecending = true;
        int prv;
        std::cin >> prv;

        for (int j = 0; j < n - 1; j++) {
            int crr;
            std::cin >> crr;  

            isAscending &= (crr >= prv);
            isDecending &= (crr <= prv);
            prv = crr;
        }
        
        std::cout << (isAscending || isDecending ? "Yes" : "No") << '\n';
    }
    return 0;
}