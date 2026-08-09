#include <iostream>
#include <vector>
#include <map>
#include <bit>
#include <cstdint>

// binary search, iterator, prefix sum
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    std::uint64_t n; 
    std::cin >> n;
    n = 63 - std::countl_zero(n);
    
    std::vector<std::uint64_t> prv = { 0 };
    
    for (std::uint64_t i = 0; i < n; i++) {
        std::vector<std::uint64_t> crr(prv.size() * 2);

        for (std::size_t j = 0; j < crr.size(); j++) {
            std::cin >> crr[j];
            crr[j] += prv[j / 2];
        }
        
        std::swap(prv, crr);
    }

    std::map<std::uint64_t, std::uint64_t> _map;
    
    for (std::size_t i = 0; i < prv.size(); i++) {
        std::uint64_t ind = (1ULL << n) + (std::uint64_t)i;
        if (_map.count(prv[i])) {
            _map[prv[i]] = std::min(_map[prv[i]], ind);
        } else {
            _map[prv[i]] = ind;
        }
    }
    
    std::uint64_t prefix = std::numeric_limits<std::uint64_t>::max();
    for (auto &[val, i] : _map) {
        prefix = std::min(prefix, i);
        i = prefix;
    }
    
    int q;
    std::cin >> q;
    
    for (int i = 0; i < q; i++) {
        std::uint64_t x;
        std::cin >> x;

        std::map<std::uint64_t, std::uint64_t>::iterator it = _map.upper_bound(x);
        if (it == _map.begin()) {
            std::cout << -1 << '\n';
        } else {
            std::cout << (--it)->second << '\n';
        }
    }
    
    return 0;
}