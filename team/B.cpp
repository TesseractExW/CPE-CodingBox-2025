#include <iostream>
#include <vector>
#include <map>
#include <bit>

// binary search, iterator, prefix sum
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    std::size_t n; 
    std::cin >> n;
    n = 63 - std::countl_zero(n);
    
    std::vector<std::size_t> prv = { 0 };
    
    for (std::size_t i = 0; i < n; i++) {
        std::vector<std::size_t> crr(prv.size() * 2);

        for (std::size_t j = 0; j < crr.size(); j++) {
            std::cin >> crr[j];
            crr[j] += prv[j / 2];
        }
        
        std::swap(prv, crr);
    }

    std::map<std::size_t, std::size_t> _map;
    
    for (std::size_t i = 0; i < prv.size(); i++) {
        if (_map.count(prv[i])) {
            _map[prv[i]] = std::min(_map[prv[i]], (1 << n) + i);
        } else {
            _map[prv[i]] = (1 << n) + i;
        }
    }
    
    std::size_t prefix = std::numeric_limits<std::size_t>::max();
    for (auto &[val, i] : _map) {
        prefix = std::min(prefix, i);
        i = prefix;
    }
    
    int q;
    std::cin >> q;
    
    for (int i = 0; i < q; i++) {
        std::size_t x;
        std::cin >> x;

        std::map<std::size_t, std::size_t>::iterator it = _map.upper_bound(x);
        if (it == _map.begin()) {
            std::cout << -1 << '\n';
        } else {
            std::cout << (--it)->second << '\n';
        }
    }
    
    return 0;
}