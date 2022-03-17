#include <iostream>
#include <utility>

int partitionLomuto(int *arr, int first, int last) {
    int pivot = arr[last];
    int index = first - 1;

    for (int i = first; i < last; ++i) {
        if (arr[i] <= pivot) {
            index++;
            std::swap(arr[index], arr[i]);
        }
    }
    if (arr[last] < arr[index + 1]) {
        std::swap(arr[index + 1], arr[last]);
    }

    return index + 1;
}

void quickSort(int *arr, int first, int last, int *counter) {
    if (first < last) {
        int pivot = partitionLomuto(arr, first, last);
        quickSort(arr, first, pivot - 1, counter);
        quickSort(arr, pivot + 1, last, counter);
        (*counter)++;
    }
}

int main() {
    int n;
    std::cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int counter = 0;
    quickSort(arr, 0, n - 1, &counter);

    counter = n == 1 ? 1 : counter;

    std::cout << counter - 1 << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}
