#include <iostream>
#include <utility>

std::pair<int, int>* mergeArr(std::pair<int, int> *p1, size_t end1, std::pair<int, int> *p2, size_t end2) {
    size_t start1 = 0, start2 = 0;
    size_t start = start1;
    size_t end = end2;
    size_t index = 0;
    std::pair<int, int> *res = new std::pair<int, int>[end1 + end2];

    while (start1 < end1 && start2 < end2) {
        if (p1[start1].first < p2[start2].first) {
            res[index] = p1[start1];
            start1++;
        } else {
            res[index] = p2[start2];
            start2++;
        }
        // std::cout << res[index].first << " - " << res[index].second << std::endl;
        index++;
    }

    if (start1 < end1) {
        for (size_t i = start1; i < end1; ++i) {
            res[index] = p1[i];
            index++;
        }
    } else {
        for (size_t i = start2; i < end2; ++i) {
            res[index] = p2[i];
            index++;
        }
    }

    return res;
}
int nearest(int64_t *arr, int n, int key) {
    int left = 0;
    int right = n - 1;
    int mid;
    while (left < right) {
        mid = left + (right - left) / 2;
        if (arr[mid] < key) {
            left = mid + 1;
        } else if (arr[mid] > key) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    int val = arr[left];
    int ind = left;
    if (left > 0) {
        if (std::abs(val - key) > std::abs(arr[left - 1] - key)) {
            val = arr[left - 1];
            ind = left - 1;
        }
    }
    if (left < n - 1) {
        if (std::abs(val - key) > std::abs(arr[left + 1] - key)) {
            val = arr[left + 1];
            ind = left + 1;
        }
    }
    return ind;
}

int partition(std::pair<int, int> *arr, int first, int last) {
    int pivot = arr[first + (last - first) / 2].first;

    size_t i = first;
    size_t j = last;

    while (!false) {
        while (arr[i].first < pivot) {
            i++;
        }
        while (arr[j].first > pivot) {
            j--;
        }
        if (i > j) {
            return j;
        } else if (i == j) {
            return -j;
        }
        std::swap(arr[i++], arr[j--]);
    }
}

void quickSort(std::pair<int, int> *arr, int first, int last) {
    if (first < last) {
        int pivot = partition(arr, first, last);
        if (pivot >= 0) {
            quickSort(arr, first, pivot);
            quickSort(arr, pivot + 1, last);
        } else {
            quickSort(arr, first, -pivot - 1);
            quickSort(arr, -pivot + 1, last);
        }
    }
}

class GemKit {
public:
    int sizes[3];
    int64_t *arr[3];
    int res[3];

    void print() {
        for (int j = 0; j < 3; ++j) {
            int size = sizes[j];
            for (int k = 0; k < size; ++k) {
                std::cout << arr[j][k] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    void printRes() {
        for (int i = 0; i < 3; ++i) {
            std::cout << res[i] << " ";
        }
        std::cout << std::endl;
    }

    ~GemKit() {
        for (int i = 0; i < 3; ++i) {
            delete[] arr[i];
        }
    }
};

int main() {
    int n, mass, size_sum = 0;
    std::cin >> n;
    int s[3];
    std::pair<int, int> *q[3];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cin >> s[j];
            size_sum += s[j];
        }
        for (int j = 0; j < 3; ++j) {
            q[j] = new std::pair<int, int>[s[j]];
            for (int k = 0; k < s[j]; ++k) {
                std::cin >> mass;
                q[j][k] = std::pair<int, int>{mass, j + 1};
            }
            quickSort(q[j], 0, s[j] - 1);
            // for (int h = 0; h < s[j]; ++h) {
            //     std::cout << q[j][h].first << " - " << q[j][h].second << std::endl;
            // }
        }
        std::pair<int, int> *a = mergeArr(q[0], s[0], q[1], s[1]);
        a = mergeArr(a, s[0] + s[1], q[2], s[2]);
        for (int j = 0; j < size_sum; ++j) {
            std::cout << a[j].first << " - " << a[j].second << std::endl;
        }
    }
    
    
    
}
