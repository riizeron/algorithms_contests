#include <iostream>
#include <utility>

int partitionHoar(int *arr, int first, int last) {
    int pivot = arr[first + (last - first) / 2];

    int i = first;
    int j = last;

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

void quickSort(int *arr, int first, int last, int *counter) {
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
