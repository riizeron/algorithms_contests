#include <iostream>
#include <string>

int *prefixFunction(std::string str) {
    int n = str.length();
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = 0;
    }
    for (int i = 1; i < n; ++i) {
        int j = arr[i - 1];
        while (j > 0 && str[i] != str[j]) {
            j = arr[j - 1];
        }
        if (str[i] == str[j]) {
            ++j;
        }
        arr[i] = j;
    }
    return arr;
}

int main() {
    std::string str;
    std::getline(std::cin, str);
    int *arr = prefixFunction(str);
    for (int i = 0; i < str.length(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete[] arr;
    return 0;
}
