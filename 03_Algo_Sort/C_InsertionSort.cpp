#include <iostream>
#include <vector>
#include <utility>

int main() {
    int size, elem;
    std::cin >> size;
    std::vector<int> data;
    for (int i = 0; i < size; ++i) {
        std::cin >> elem;
        data.push_back(elem);
    }

    int counter = 0;
    int tmp, j;
    for (int i = 1; i < size; ++i) {
        tmp = data[i];
        j = i;
        if (data[j - 1] <= tmp) {
            counter++;
        }
        while (j > 0 && data[j - 1] > tmp) {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = tmp;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl << counter << std::endl;
}
