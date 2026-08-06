#include <iostream>
#include <vector>
#include <numeric>

// disjointed set, path compression
class TerritoryDisjointedSet {
private:
    std::vector<int> parents, areas;
    int mostArea = 0;

    int find(int crr) {
        if (parents[crr] == crr) {
            return crr;
        } else {
            return parents[crr] = find(parents[crr]);
        }
    }

    bool unite(int i, int j) {
        int a = find(i);
        int b = find(j);

        if (a == b) {
            return false;
        } else if (areas[a] < areas[b]) {
            return unite(b, a);
        }

        parents[b] = a;
        areas[a] += areas[b] / 2;

        if (areas[a] > areas[mostArea] || (
            areas[a] == areas[mostArea] && a < mostArea)) 
        {
            mostArea = a;
        }
        return true;
    }

public:
    TerritoryDisjointedSet(std::vector<int> _areas) {
        areas = _areas;

        parents.resize(areas.size());
        std::iota(parents.begin(), parents.end(), 0);

        for (std::size_t i = 0; i < parents.size(); i++) {
            if (areas[i] > areas[mostArea]) {
                mostArea = i;
            }
        }
    }

    std::pair<int, int> query() {
        return { mostArea + 1, areas[mostArea] };
    }

    void fight(int a, int b) {
        unite(a - 1, b - 1);
    }
};

int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::size_t n, q;
    std::cin >> n >> q;

    std::vector<int> areas(n);
    for (int &area : areas) {
        std::cin >> area;
    }
    
    TerritoryDisjointedSet _dset(areas);

    for (std::size_t i = 0; i < q; i++) {
        char cmd;
        std::cin >> cmd;
        int a, b;

        switch (cmd) {
        case 'A':
            std::cin >> a >> b;

            _dset.fight(a, b);
            break;
        default:
            std::cout << _dset.query().first << ' ' << _dset.query().second << '\n';
            break;
        }
    }

    return 0;
}