#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    int value;
    std::cin >> value;
    // int64_t x = 640;
    // int eps = 1e-5;
    // while (x * x + std::sqrt(x) - value > eps) {
    //     x -= (x * x + std::sqrt(x) - value) / (2 * x + 1 / (2 * std::sqrt(x)));
    // }
    // std::cout << std::fixed << std::setprecision(10) << x << std::endl;
    double right = 1;
    while (right * right + std::sqrt(right) < value) {
        right *= 2;
    }
    double left = 1;
    while (left * left + std::sqrt(left) > value) {
        left *= 2;
    }
    double mid;
    while (std::abs(right - left) > 1e-9) {
        mid = left + (right - left) / 2;
        if (value > std::pow(mid, 2) + std::sqrt(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    std::cout << std::fixed << std::setprecision(10) << mid << std::endl;
}
