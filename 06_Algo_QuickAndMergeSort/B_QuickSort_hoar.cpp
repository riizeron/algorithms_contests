#include <iostream>
#include <utility>

int partitionHoar(int *arr, size_t first, size_t last) {
    int pivot = arr[first + (last - first) / 2];

    size_t i = first;
    size_t j = last;

    while (!false) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i > j) {
            return j;
        } else if (i == j) {
            return -j;
        }
        std::swap(arr[i++], arr[j--]);
    }
}

void quickSort(int *arr, size_t first, size_t last, size_t *counter) {
    if (first < last) {
        int pivot = partitionHoar(arr, first, last);
        if (pivot >= 0) {
            quickSort(arr, first, pivot, counter);
            quickSort(arr, pivot + 1, last, counter);
        } else {
            quickSort(arr, first, -pivot - 1, counter);
            quickSort(arr, -pivot + 1, last, counter);
        }
        (*counter)++;
    }
}

int main() {
    size_t n;
    std::cin >> n;

    int *arr = new int[n];
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    size_t counter = 0;

    quickSort(arr, 0, n - 1, &counter);

    counter = n == 1 ? 1 : counter;
    std::cout << counter - 1 << std::endl;
    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}
