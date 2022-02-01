#include <iostream>

int main() {
    int amount, how_much;
    std::cin >> amount >> how_much;
    int max_wire = 0;
    int* wires = new int[amount];
    int wire;
    for (int i = 0; i < amount; ++i) {
        std::cin >> wire;
        max_wire = wire > max_wire ? wire : max_wire;
        wires[i] = wire;
    }

    int left = 0;
    int right = max_wire + 1;
    int mid = left + (right - left) / 2;
    int sum;
    while (left < right) {
        sum = 0;
        for (int i = 0; i < amount; ++i) {
            sum += wires[i] / mid;
        }
        if (sum < how_much) {
            right = mid;
        } else {
            left = mid + 1;
        }
        mid = left + (right - left) / 2;
    }

    std::cout << left - 1 << std::endl;

    delete[] wires;
}
