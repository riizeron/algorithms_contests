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
    int min = 0;
    for (int i = 0; i < size - 1; ++i) {
        min = i;
        for (int j = i + 1; j < size; ++j) {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        if (min != i) {
            std::swap(data[i], data[min]);
            counter++;
        }
    }

    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl << counter << std::endl;
}
