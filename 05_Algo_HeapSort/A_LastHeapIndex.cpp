#include <iostream>

int search(int* arr, int n) {
    int left, right;
    int i = 0;
    for (int i = 0; i < n; ++i) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        if (left < n && arr[i] < arr[left]) {
            return left;
        } else if (right < n && arr[i] < arr[right]) {
            return right - 1;
        }
    }
    return n - 1;
}

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << search(arr, n) << std::endl;
    delete[] arr;
    return 0;
}
