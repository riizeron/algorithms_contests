#include <iostream>
#include <utility>

class BinHeap {
private:
    std::pair<int, int>* arr_;
    int size_;
    int len_;
    void swiftDown(int i);
    void swiftUp(int i);

public:
    explicit BinHeap(int len);
    ~BinHeap();
    void insert(std::pair<int, int> key);
    std::pair<int, int>* getSorted();
    std::pair<int, int> extractRoot();
};

BinHeap::BinHeap(int len) : size_(0) {
    this->len_ = len;
    arr_ = new std::pair<int, int>[len];
}

BinHeap::~BinHeap() {
    delete[] arr_;
}

std::pair<int, int>* BinHeap::getSorted() {
    std::pair<int, int>* a = new std::pair<int, int>[size_];
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

        if (right < size_ && arr_[right].second < arr_[left].second) {
            j = right;
        }
        if (arr_[i].second <= arr_[j].second) {
            break;
        }
        std::swap(arr_[i], arr_[j]);
        i = j;
    }
}

void BinHeap::swiftUp(int i) {
    while (arr_[i].second < arr_[(i - 1) / 2].second) {
        std::swap(arr_[i], arr_[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void BinHeap::insert(std::pair<int, int> key) {
    size_++;
    arr_[size_ - 1] = key;
    swiftUp(size_ - 1);
}

std::pair<int, int> BinHeap::extractRoot() {
    std::pair<int, int> root = arr_[0];
    arr_[0] = arr_[size_ - 1];
    size_--;
    swiftDown(0);
    return root;
}

int binSearch(std::pair<int, int>* arr, int n, int key) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (arr[mid].second < key) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (left < n - 1) {
        if (std::abs(arr[left + 1].second - key) <= std::abs(arr[left].second - key)) {
            return arr[left + 1].first;
        }
    }
    if (left > 0) {
        if (std::abs(arr[left - 1].second - key) <= std::abs(arr[left].second - key)) {
            return arr[left - 1].first;
        }
    }
    return arr[left].first;
}

int main() {
    int n;
    std::cin >> n;
    int* poselki = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> poselki[i];
    }

    int k;
    std::pair<int, int> elem;
    std::cin >> k;
    BinHeap* heap = new BinHeap(k);
    for (int i = 0; i < k; ++i) {
        elem.first = i + 1;
        std::cin >> elem.second;
        heap->insert(elem);
    }
    std::pair<int, int>* fallouts = heap->getSorted();

    for (int i = 0; i < n; ++i) {
        std::cout << binSearch(fallouts, k, poselki[i]) << " ";
    }
    std::cout << std::endl;

    delete heap;
    delete[] poselki;
    delete[] fallouts;
    return 0;
}
