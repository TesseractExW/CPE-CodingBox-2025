#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cassert>

// sorting, priority queue, min/max heap, OOP
class task {
public:    
    int difficulty, priority; 
    std::string name; 

    task(int d, int p, const std::string &n)
        : difficulty(d), priority(p), name(n) 
    {
        assert(d != 0);
    };
};

auto cmp_function = [](const task &a, const task &b) {
    int r1 = a.priority * b.difficulty;
    int r2 = b.priority * a.difficulty;

    if (r1 != r2) {
        return r1 < r2;
    } else {
        return a.name < b.name;
    }
};

int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    
    std::priority_queue<task, std::vector<task>, decltype(cmp_function)> _pqueue;
    std::string cmd;

    while (std::cin >> cmd && cmd != "EXIT" && (cmd != "PROCESS" || !_pqueue.empty())) {
        if (cmd == "PROCESS") {
            std::cout << _pqueue.top().name << '\n';
            _pqueue.pop();
        } else if (cmd == "PEEK") {
            std::cout << _pqueue.top().name << '\n';
        } else if (cmd == "COUNT") {
            std::cout << _pqueue.size() << '\n';
        } else {
            int d, p;
            std::string n;
            std::cin >> n >> d >> p;

            _pqueue.push(task(d, p, n));
        }
    }

    std::cout << "GOOD BYE";

    return 0;
}