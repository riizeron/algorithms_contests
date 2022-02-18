#include <iostream>
#include <vector>
#include <utility>

template <class ValueType>
class Heap {
public:
    Heap();

    template <class Iterator>
    Heap(Iterator begin, Iterator end);

    Heap(std::initializer_list<ValueType>);

    Heap(const Heap &);
    Heap &operator=(const Heap &);

    Heap(Heap &&);
    Heap &operator=(Heap &&);

    ~Heap();

    size_t size() const;
    bool empty() const;

    void insert(const ValueType &);
    ValueType extract();

private:
    size_t size_;
    std::vector<ValueType> arr_;
    void shiftDown(int);
    void shiftUp(int);
};

template <class ValueType>
size_t Heap<ValueType>::size() const {
    return size_;
}

template <class ValueType>
bool Heap<ValueType>::empty() const {
    return arr_.empty();
}

template <class ValueType>
void Heap<ValueType>::insert(const ValueType &key) {
    size_++;
    arr_.push_back(key);
    shiftUp(size_ - 1);
}

template <class ValueType>
Heap<ValueType>::Heap() : size_(0) {
    arr_.clear();
}

template <class ValueType>
Heap<ValueType>::~Heap() {
    arr_.clear();
    size_ = 0;
}

template <class ValueType>
template <class Iterator>
Heap<ValueType>::Heap(Iterator begin, Iterator end) : size_(0) {
    arr_.clear();
    for (auto iter = begin; iter != end; ++iter) {
        arr_.push_back(*iter);
        size_++;
    }
}

template <class ValueType>
Heap<ValueType>::Heap(std::initializer_list<ValueType> list) : size_(0) {
    arr_.clear();
    for (auto elem : list) {
        arr_.push_back(elem);
        ++size_;
    }
}

template <class ValueType>
Heap<ValueType>::Heap(const Heap &h) : size_(h.size_) {
    arr_.clear();
    for (auto elem : h.arr_) {
        arr_.push_back(elem);
    }
}

template <class ValueType>
Heap<ValueType> &Heap<ValueType>::operator=(const Heap<ValueType> &h) {
    if (this == &h) {
        return *this;
    }
    arr_.clear();
    size_ = h.size_;
    for (auto elem : h.arr_) {
        arr_.push_back(elem);
    }
    return *this;
}

template <class ValueType>
Heap<ValueType>::Heap(Heap &&h) : size_(h.size_) {
    arr_.clear();
    for (int i = 0; i < size_; ++i) {
        arr_.push_back(h.arr_.at(i));
    }
    h.size_ = 0;
    h.arr_.clear();
}

template <class ValueType>
Heap<ValueType> &Heap<ValueType>::operator=(Heap<ValueType> &&h) {
    if (&h == this) {
        return *this;
    }
    arr_.clear();
    for (int i = 0; i < h.size_; ++i) {
        arr_.at(i).push_back(h.arr_.at(i));
    }
    // arr_ = h.arr_;
    size_ = h.size_;
    h.arr_.clear();
    h.size_ = 0;
    return *this;
}

template <class ValueType>
ValueType Heap<ValueType>::extract() {
    int root = arr_.at(0);
    arr_.at(0) = arr_.at(size_ - 1);
    size_--;
    shiftDown(0);
    return root;
}

template <class ValueType>
void Heap<ValueType>::shiftDown(int i) {
    int left, right, lar;
    while (2 * i + 2 < size_) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        lar = i;
        if (left < size_ && arr_.at(lar) < arr_.at(left)) {
            lar = left;
        }
        if (right < size_ && arr_.at(lar) < arr_.at(right)) {
            lar = right;
        }
        if (lar == i) {
            break;
        }
        std::swap(arr_.at(i), arr_.at(lar));
        i = lar;
    }
}

template <class ValueType>
void Heap<ValueType>::shiftUp(int i) {
    while (arr_.at(i) > arr_.at((i - 1) / 2)) {
        std::swap(arr_.at(i), arr_.at((i - 1) / 2));
        i = (i - 1) / 2;
    }
}

// int main() {
//     Heap<int> h{1, 2, 3};
//     Heap<int> *g = new Heap<int>();
//     g = &h;
//     std::cout << h.empty() << std::endl;
// }
