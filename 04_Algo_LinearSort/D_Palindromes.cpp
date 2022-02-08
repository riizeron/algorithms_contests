#include <iostream>
#include <string>
#include <vector>

std::string simpleCountingPalindromGenerator(std::string a, int n, int min, int max) {
    int k = max - min + 1;
    int *c = new int[k];
    std::vector<char> syms;
    for (int i = 0; i < k; ++i) {
        c[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        c[a[i] - min]++;
    }
    for (int i = 0; i < k; ++i) {
        while (c[i] > 1) {
            syms.push_back(static_cast<char>(i + min));
            c[i] -= 2;
        }
    }
    int ind = 0;
    for (int i = 0; i < k; ++i) {
        if (c[i]) {
            syms.push_back(static_cast<char>(i + min));
            ind++;
            break;
        }
    }
    for (int i = syms.size() - 1 - ind; i >= 0; --i) {
        syms.push_back(syms[i]);
    }
    delete[] c;
    std::string str(syms.begin(), syms.end());
    return str;
}

int main() {
    int n;
    std::cin >> n;
    std::string letters;
    std::cin >> letters;

    letters = simpleCountingPalindromGenerator(letters, n, 'A', 'Z');

    std::cout << letters << std::endl;
    return 0;
}
