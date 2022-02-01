#include <iostream>
#include <algorithm>
#include <vector>

bool qwerty(int mid, std::vector<int> pupils, int amount_n, int amount_r, int amount_c) {
    int counter = 0;
    int iter = 0;
    while (iter < amount_n - amount_c + 1) {
        if (pupils[iter + amount_c - 1] - pupils[iter] <= mid) {
            counter++;
            iter += amount_c;
        } else {
            iter++;
        }
    }
    return counter < amount_r;
}

int main() {
    int amount_n, amount_r, amount_c;
    std::cin >> amount_n >> amount_r >> amount_c;

    std::vector<int> pupils;
    int pupil;
    for (int i = 0; i < amount_n; ++i) {
        std::cin >> pupil;
        pupils.push_back(pupil);
    }

    std::sort(pupils.begin(), pupils.end());
    if (amount_n == amount_c) {
        std::cout << pupils[amount_n - 1] - pupils[0] << std::endl;
        return 0;
    }

    int left = 0;
    int right = pupils[amount_n - 1] - pupils[0];
    int min = right;
    int mid = left + (right - left) / 2;
    while (left < right) {
        if (!qwerty(mid, pupils, amount_n, amount_r, amount_c)) {
            right = mid;
            if (mid < min) {
                min = mid;
            }
        } else {
            left = mid + 1;
        }
        mid = left + (right - left) / 2;
    }

    std::cout << min << std::endl;
    return 0;
}
