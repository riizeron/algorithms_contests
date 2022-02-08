#include <iostream>

int *stableCountingSort(int *a, int n, int min, int max) {
    int k = max - min + 1;
    int *c = new int[k];
    int *b = new int[n];
    for (int i = 0; i < k; ++i) {
        c[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        c[a[i] - min]++;
    }
    for (int j = 1; j < k; ++j) {
        c[j] = c[j] + c[j - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        c[a[i] - min]--;
        b[c[a[i] - min]] = a[i];
    }
    delete[] c;
    delete[] a;
    return b;
}

int main() {
    int n, max = INT32_MIN, min = INT32_MAX, elem;
    std::cin >> n;
    int *numbers = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> elem;
        if (elem > max) {
            max = elem;
        }
        if (elem < min) {
            min = elem;
        }
        numbers[i] = elem;
    }
    numbers = stableCountingSort(numbers, n, min, max);
    for (int i = 0; i < n; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    delete[] numbers;
    return 0;
}
