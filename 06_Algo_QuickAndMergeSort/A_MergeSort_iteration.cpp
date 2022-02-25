#include <iostream>

void mergeArr(int *arr, size_t block_i, size_t size, size_t n) {
    size_t left_i = 0;
    size_t right_i = 0;
    size_t left = block_i;
    size_t mid = left + size;
    size_t right = mid + size > n ? n : mid + size;

    int *block = new int[right - left];

    while (left + left_i < mid && mid + right_i < right) {
        if (arr[left + left_i] < arr[mid + right_i]) {
            block[left_i + right_i] = arr[left + left_i];
            left_i++;
        } else {
            block[left_i + right_i] = arr[mid + right_i];
            right_i++;
        }
    }

    while (left + left_i < mid) {
        block[left_i + right_i] = arr[left + left_i];
        left_i++;
    }
    while (mid + right_i < right) {
        block[left_i + right_i] = arr[mid + right_i];
        right_i++;
    }

    for (int i = 0; i < left_i + right_i; ++i) {
        arr[left + i] = block[i];
    }

    delete[] block;
}

void mergeSort(int *arr, int n) {
    for (size_t size_i = 1; size_i < n; size_i *= 2) {
        for (size_t block_i = 0; block_i < n - size_i; block_i += 2 * size_i) {
            mergeArr(arr, block_i, size_i, n);
        }
    }
}

int main() {
    size_t n;
    std::cin >> n;
    int *arr = new int[n];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    mergeSort(arr, n);

    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}
