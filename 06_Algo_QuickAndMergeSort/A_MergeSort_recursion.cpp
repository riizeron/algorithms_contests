#include <iostream>

void mergeArr(int *arr, int start1, int end1, int start2, int end2) {
    int start = start1;
    int end = end2;
    int index = 0;
    int *res = new int[end1 + end2 + 2];

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
        for (int i = start1; i <= end1; ++i) {
            res[index] = arr[i];
            index++;
        }
    } else {
        for (int i = start2; i <= end2; ++i) {
            res[index] = arr[i];
            index++;
        }
    }

    index = 0;
    for (int i = start; i <= end; ++i) {
        arr[i] = res[index];
        index++;
    }

    delete[] res;
}

void mergeSort(int *arr, int first, int last) {
    int mid = first + (last - first) / 2;

    if (first < last) {
        mergeSort(arr, first, mid);
        mergeSort(arr, mid + 1, last);
        mergeArr(arr, first, mid, mid + 1, last);
    }
}

int main() {
    int n;
    std::cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}
