#include <iostream>

int main() {
    int dwarf;
    int max_dw_f = -1, max_dw_s = -1;
    do {
        std::cin >> dwarf;
        if (dwarf > max_dw_f) {
            max_dw_s = max_dw_f;
            max_dw_f = dwarf;
            continue;
        }
        if (dwarf > max_dw_s) {
            max_dw_s = dwarf;
        }
    } while (dwarf != 0);

    std::cout << max_dw_f << std::endl << max_dw_s << std::endl;
}
