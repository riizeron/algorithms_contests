#include <iostream>
#include <cmath>


class BinHeap {
private:
    int* arr;
    int size;
    void swift_down(int i);
    void swift_up(int i);

public:
    BinHeap(int len);
    ~BinHeap();
    int extract_min();
    void insert(int key);
    int search(int key);
    void print();
};

BinHeap::BinHeap(int len) {
    this->arr = new int[len];
    size = 0;
}
BinHeap::~BinHeap() {
    delete[] arr;
}

void BinHeap::print() {
    int counter = 0;
    int k = 0;
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
        if (counter == i) {
            std::cout << std::endl;
            counter += std::pow(2,++k);
        }
    }
    std::cout << std::endl;
}

void BinHeap::swift_down(int i) {
    int left, right, lar;
    while (2 * i + 1 < size) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        lar = i;
        if (left < size && arr[lar] < arr[left]) {
            lar = left;
        }
        if (right < size && arr[lar] < arr[right]) {
            lar = right;
        }
        if (lar == i) {
            break;
        }
        std::swap(arr[i], arr[lar]);
        i = lar;
    }
}

void BinHeap::swift_up(int i) {
    while (arr[i] > arr[(i - 1) / 2]) {
        std::swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void BinHeap::insert(int key) {
    size++;
    arr[size - 1] = key;
    swift_up(size - 1);
}

int BinHeap::search(int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int BinHeap::extract_min() {
    int min = arr[0];
    arr[0] = arr[size - 1];
    size--;
    swift_down(0);
    return min;
}

int main() {
    int n, elem;
    std::cin >> n;
    BinHeap *heap = new BinHeap(n);
    for (int  i = 0; i < n; ++i) {
        std::cin >> elem;
        heap->insert(elem);
    }
    heap->print();

    delete heap;
    return 0;
}