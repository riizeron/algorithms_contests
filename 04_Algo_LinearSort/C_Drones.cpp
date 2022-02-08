#include <iostream>

int64_t digit(int64_t x, int i) {
    return (255ll << (8 * i) & x) >> (8 * i);
}
struct Drone {
    int id;
    int64_t mass;
};

Drone* droneLSDSort(Drone* a, int n) {
    int* c = new int[256];
    Drone* b = new Drone[n];
    int d;
    for (int dgt = 0; dgt < 4; ++dgt) {
        for (int j = 0; j < 256; ++j) {
            c[j] = 0;
        }
        for (int j = 0; j < n; ++j) {
            d = digit(a[j].mass, dgt);
            c[d]++;
        }
        for (int j = 256 - 2; j >= 0; --j) {
            c[j] += c[j + 1];
        }
        for (int j = n - 1; j >= 0; --j) {
            d = digit(a[j].mass, dgt);
            c[d]--;
            b[c[d]] = a[j];
        }
        for (int j = 0; j < n; ++j) {
            a[j] = b[j];
        }
    }
    delete[] c;
    delete[] b;
    return a;
}

int main() {
    int n, id;
    int64_t mass;
    std::cin >> n;
    Drone* drones = new Drone[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> id >> mass;
        drones[i] = {id, mass};
    }
    drones = droneLSDSort(drones, n);
    for (int i = 0; i < n; ++i) {
        std::cout << drones[i].id << "\t" << drones[i].mass << std::endl;
    }
    delete[] drones;
    return 0;
}
