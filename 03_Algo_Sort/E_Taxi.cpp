#include <iostream>
#include <utility>
#include <vector>
#include <string>

int main() {
    int elem;
    std::vector<int64_t> vec_m;
    while (std::cin >> elem) {
        vec_m.push_back(elem);
    }
    std::vector<int64_t> vec_f(vec_m.begin(), vec_m.begin() + vec_m.size() / 2);
    std::vector<int64_t> vec_s(vec_m.begin() + vec_m.size() / 2, vec_m.end());
    for (int i = 0; i < vec_f.size() - 1; ++i) {
        for (int j = 0; j < vec_f.size() - 1 - i; ++j) {
            if (vec_f[j] > vec_f[j + 1]) {
                std::swap(vec_f[j], vec_f[j + 1]);
            }
            if (vec_s[j] > vec_s[j + 1]) {
                std::swap(vec_s[j], vec_s[j + 1]);
            }
        }
    }
    int64_t sum = 0;
    for (int i = 0; i < vec_f.size(); ++i) {
        sum += vec_f[i] * vec_s[vec_s.size() - i - 1];
    }

    std::cout << sum << std::endl;
}
