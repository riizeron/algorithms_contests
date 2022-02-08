#include <iostream>

int digit(int x, int dgt) {
    return (255 << (8 * dgt) & ) >> (8 * dgt);
}

int* msd(int *a, int n, int l, int r, int d) {
    int* c = new int[256];
    int* b = new int[n];
    if (d > 4 || l >= r) {
        return a;
    }
    for (int i = 0; i < 256; ++i) {
        c[i] = 0;
    }
    int dgt;
    for (int i = l; i < r; ++i) {
        dgt = digit(a[i], d);
        c[dgt + 1]++;
    }
    for (int i = 1; i < 256; ++i) {
        c[i] +=c[i - 1];
    }
    for (int i = l; i < r; ++i) {
        dgt = digit(a[i], d);
        c[l + ]
    }
    return a;
}

int main() {
    int n, id, mass;
    std::cin >> n;
    int* numbers = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    numbers = msd(numbers, n);
    


    delete[] numbers;
    return 0;
}