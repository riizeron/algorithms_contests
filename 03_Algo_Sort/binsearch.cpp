#include <iostream>
#include <vector>

int binSearch(std::vector<int> data, int left, int right, int key) {
    int mid;
    while (right > left) {
        mid = left + (right - left) / 2;
        if (data[mid] < key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    int size, elem;
    std::cin >> size;
    std::vector<int> data;
    for (int i = 0; i < size; ++i) {
        std::cin >> elem;
        data.push_back(elem);
    }
    std::cout << binSearch(data, 0, data.size() - 1, 5) << std::endl;

}