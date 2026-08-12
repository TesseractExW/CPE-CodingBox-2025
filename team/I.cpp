#include <iostream>

// string manipulation
int main(int argc, char *argv[]) {
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    char last = '\0';
    for (char ch : s) {
        ch = tolower(ch);
        if (isalpha(ch) && ch != last) {
            std::cout << ch;
        }
        last = ch;
    }
    return 0;
}
