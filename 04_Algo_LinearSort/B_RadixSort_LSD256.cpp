#include <iostream>

int digit(int x, int dgt) {
    return (255 << (8 * dgt) & x) >> (8 * dgt);
}

int* lsd(int* a, int n) {
    int* c = new int[256];
    int* b = new int[n];
    int d;
    for (int dgt = 0; dgt < 4; ++dgt) {
        for (int j = 0; j < 256; ++j) {
            c[j] = 0;
        }
        for (int j = 0; j < n; ++j) {
            d = digit(a[j], dgt);
            c[d]++;
        }
        for (int j = 1; j < 256; ++j) {
            c[j] += c[j - 1];
        }
        for (int j = n - 1; j >= 0; --j) {
            d = digit(a[j], dgt);
            c[d]--;
            b[c[d]] = a[j];
        }
        for (int j = 0; j < n; ++j) {
            a[j] = b[j];
        }
    }
    delete[] c;
    delete[] b;
    return a;
}

int main() {
    int n;
    std::cin >> n;
    int* numbers = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    numbers = lsd(numbers, n);
    for (int i = 0; i < n; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    delete[] numbers;
    return 0;
}
