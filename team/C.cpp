#include <iostream>
#include <cmath>
#include <iomanip>

// math, geometry
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::cout << n * n * n << ' ' ;
    std::cout << std::fixed << std::setprecision(10) << std::sqrtl(3) * n * n;
    return 0;
}