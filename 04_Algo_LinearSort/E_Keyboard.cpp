#include <iostream>

int main() {
    int n, tab;
    std::cin >> n;
    int* health = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> health[i];
    }
    int k;
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
        std::cin >> tab;
        health[tab - 1]--;
    }
    for (int i = 0; i < n; ++i) {
        if (health[i] >= 0) {
            std::cout << "no" << std::endl;
        } else {
            std::cout << "yes" << std::endl;
        }
    }
}
