#include <iostream>
#include <utility>

class BinHeap {
private:
    int64_t* arr_;
    int size_;
    int len_;
    void swiftDown(int i);
    void swiftUp(int i);

public:
    explicit BinHeap(int len);
    ~BinHeap();
    void insert(int64_t key);
    void print();
    int64_t* getSorted();
    int64_t extractRoot();
};

BinHeap::BinHeap(int len) {
    this->arr_ = new int64_t[len];
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

int64_t* BinHeap::getSorted() {
    int64_t* a = new int64_t[len_];
    for (int i = 0; i < len_; ++i) {
        a[i] = extractRoot();
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

void BinHeap::insert(int64_t key) {
    size_++;
    arr_[size_ - 1] = key;
    swiftUp(size_ - 1);
}

int64_t BinHeap::extractRoot() {
    int root = arr_[0];
    arr_[0] = arr_[size_ - 1];
    size_--;
    swiftDown(0);
    return root;
}

int leftBinSearch(int64_t* a, int n, int64_t key) {
    int right = n;
    int left = 0;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (a[mid] < key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int rightBinSearch(int64_t* a, int n, int64_t key) {
    int left = 0;
    int right = n;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (a[mid] > key) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return right - 1;
}

int main() {
    int n;
    std::cin >> n;
    int64_t* lefts;
    int64_t* rights;
    BinHeap* heapa = new BinHeap(n);
    BinHeap* heapb = new BinHeap(n);
    int64_t a, b;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        heapa->insert(a);
        heapb->insert(b);
    }
    lefts = heapa->getSorted();
    rights = heapb->getSorted();

    char g;
    int64_t e;
    while (g != '!') {
        std::cin >> g;
        if (g == '!') {
            continue;
        }
        std::cin >> e;
        std::cout << "! " << rightBinSearch(lefts, n, e) - rightBinSearch(rights, n, e)
                  << std::endl;
    }
    delete[] rights;
    delete[] lefts;
    return 0;
}
