#include <iostream>
#include <utility>

class BinHeap {
private:
    int* arr_;
    int size_;
    int len_;
    void swiftDown(int i);
    void swiftUp(int i);

public:
    explicit BinHeap(int len);
    ~BinHeap();
    void insert(int key);
    void print();
    int* getSorted();
    int extractMin();
};

BinHeap::BinHeap(int len) {
    this->arr_ = new int[len];
    this->len_ = len;
    size_ = 0;
}

BinHeap::~BinHeap() {
    delete[] arr_;
}

void BinHeap::print() {
    for (int i = 0; i < size_; ++i) {
        std::cout << arr_[i] << " ";
    }
    std::cout << std::endl;
}

int* BinHeap::getSorted() {
    int* a = new int[len_];
    for (int i = 0; i < len_; ++i) {
        a[i] = extractMin();
    }
    return a;
}

void BinHeap::swiftDown(int i) {
    int left, right, j;
    while (2 * i + 1 < size_) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        j = left;

        if (right < size_ && arr_[right] < arr_[left]) {
            j = right;
        }
        if (arr_[i] <= arr_[j]) {
            break;
        }
        std::swap(arr_[i], arr_[j]);
        i = j;
    }
}

void BinHeap::swiftUp(int i) {
    while (arr_[i] < arr_[(i - 1) / 2]) {
        std::swap(arr_[i], arr_[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void BinHeap::insert(int key) {
    size_++;
    arr_[size_ - 1] = key;
    swiftUp(size_ - 1);
}

int BinHeap::extractMin() {
    int min = arr_[0];
    arr_[0] = arr_[size_ - 1];
    size_--;
    swiftDown(0);
    return min;
}

int main() {
    int n, elem;
    std::cin >> n;
    BinHeap* heap = new BinHeap(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> elem;
        heap->insert(elem);
    }
    heap->print();
    std::cin >> elem;
    heap->insert(elem);
    heap->print();
    // int* res = heap->getSorted();
    // for (int i = 0; i < n; ++i) {
    //     std::cout << res[i] << " ";
    // }
    // std::cout << std::endl;

    delete heap;
    return 0;
}
