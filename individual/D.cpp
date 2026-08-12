#include <iostream>
#include <deque>
#include <string>
#include <vector>

// stack, queue
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string str;
    std::cin >> str;

    std::deque<std::size_t> _deque;
    _deque.push_back(0);

    for (std::size_t i = 0; i < str.size(); i++) {
        if (str[i] == '<') {
            _deque.push_back(i + 1);
        } else {
            _deque.push_front(i + 1);
        }
    }

    std::size_t curr = 1;
    std::vector<std::size_t> result(str.size() + 1);
    while (!_deque.empty()) {
        std::size_t front = _deque.front();
        _deque.pop_front();

        result[front] = curr++;
    }

    for (std::size_t position : result) {
        std::cout << position << '\n';
    }

    return 0;
}
