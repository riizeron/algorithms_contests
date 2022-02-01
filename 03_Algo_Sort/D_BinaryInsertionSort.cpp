#include <iostream>
#include <utility>

int binSearch(int* data, int left, int right, int key) {
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (data[mid] > key) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right;
}
int main() {
    int size, elem;
    std::cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int j, counter = 0;
    for (int i = 1; i < size; ++i) {
        j = i;
        elem = binSearch(arr, 0, j, arr[i]);
        while (j > elem) {
            std::swap(arr[j], arr[j - 1]);
            j--;
            counter++;
        }
    }

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << counter << std::endl;
    delete[] arr;
    return 0;
}
