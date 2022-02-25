#include <iostream>

void mergeArr(int *arr, size_t start1, size_t end1, size_t start2, size_t end2) {
    size_t start = start1;
    size_t end = end2;
    size_t index = 0;
    size_t *res = new size_t[end1 + end2 + 2];

    while (start1 <= end1 && start2 <= end2) {
        if (arr[start1] < arr[start2]) {
            res[index] = arr[start1];
            start1++;
        } else {
            res[index] = arr[start2];
            start2++;
        }
        index++;
    }

    if (start1 <= end1) {
        for (size_t i = start1; i <= end1; ++i) {
            res[index] = arr[i];
            index++;
        }
    } else {
        for (size_t i = start2; i <= end2; ++i) {
            res[index] = arr[i];
            index++;
        }
    }

    index = 0;
    for (size_t i = start; i <= end; ++i) {
        arr[i] = res[index];
        index++;
    }

    delete[] res;
}

void mergeSort(int *arr, size_t first, size_t last) {
    size_t mid = first + (last - first) / 2;

    if (first < last) {
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        mergeArr(arr, first, mid, mid + 1, last);
    }
}

int main() {
    size_t n;
    std::cin >> n;
    int *arr = new int[n];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}
