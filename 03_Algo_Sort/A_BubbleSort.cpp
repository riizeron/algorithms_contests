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
    bool flag = true;
    int iii = 0;
    while (flag) {
        flag = false;
        for (int j = 0; j < size - 1 - iii; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                flag = true;
                counter++;
            }
        }
        iii++;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }

    std::cout << std::endl << counter << std::endl;
    return 0;
}
