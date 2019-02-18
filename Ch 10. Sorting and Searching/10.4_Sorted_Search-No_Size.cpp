#include <iostream>
#include <vector>
#include <initializer_list>

using std::cout;
using std::endl;
using std::vector;

template<class T>
class Listy {
 private:
  vector<T> storage;
 public:
  explicit Listy(T a) {
    storage.push_back(a);
  }
  Listy(std::initializer_list<T> ll) {
    for (T l : ll) {
      storage.push_back(l);
    }
  }
  T at(int i) const {
    if (i >= storage.size()) {
      return -1;
    } else {
      return storage[i];
    }
  }
};

template<class T>
int find(const Listy<T> &listy, T x) {
  // Find the right boundary
  int right = 1;
  while (listy.at(right) > 0 && listy.at(right) < x) {
    right <<= 1;
  }
  // Binary search
  int left = right / 2;
  while (left <= right) {
    int middle = (left + right) / 2;
    if (x == listy.at(middle)) {
      return middle;
    } else if (listy.at(left) < 0) {
      return -1;
    } else if (x < listy.at(middle) || listy.at(middle) == -1) {
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }
  return -1;
}

int main() {
  Listy<int> listy({1, 2, 3, 4, 5});

  cout << find<>(listy, 2) << endl;
  cout << find<>(listy, 5) << endl;

  return 0;
}

/*
  Runtime O(log n)
 */
