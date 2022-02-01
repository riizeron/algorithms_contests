#include <iostream>

int leftBS(int *line, int len, int key) {
    int mid = len / 2;
    int right = len;
    int left = 0;

    while (left < right) {
        if (key > line[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
        mid = left + (right - left) / 2;
    }
    return left;
}

int rightBS(int *line, int len, int key) {
    int mid = len / 2;
    int right = len;
    int left = 0;

    while (left < right) {
        if (key < line[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
        mid = left + (right - left) / 2;
    }
    return right - 1;
}

int main() {
    int n_fir, n_sec;
    std::cin >> n_fir >> n_sec;
    int *line = new int[n_fir];

    for (int i = 0; i < n_fir; ++i) {
        std::cin >> line[i];
    }

    int elem;
    for (int i = 0; i < n_sec; ++i) {
        std::cin >> elem;
        int right = rightBS(line, n_fir, elem);
        int left = leftBS(line, n_fir, elem);
        if (right == n_fir || left == n_fir || left > right) {
            std::cout << 0 << std::endl;
            continue;
        }
        std::cout << leftBS(line, n_fir, elem) + 1 << " " << rightBS(line, n_fir, elem) + 1
                  << std::endl;
    }

    delete[] line;
}
