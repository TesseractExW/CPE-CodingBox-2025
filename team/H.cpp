#include <iostream>
#include <cstdint>

// prefix sums, math
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::int64_t a, b;
    std::cin >> a >> b;
    a--;

    std::cout << b / 3 - b / 15 - a / 3 + a / 15 << ' '; 
    std::cout << b / 5 - b / 15 - a / 5 + a / 15 << ' '; 
    std::cout << b / 15 - a / 15;

    return 0;
}
