#include <iostream>

using std::cout;
using std::endl;

class Bitset {
 private:
  int *_bitset;
  int _size;

 public:
  explicit Bitset(int size) : _size(size) {
    _bitset = new int[(size >> 5) + 1]{};  // divide by 32
  }
  ~Bitset() {
    delete [] _bitset;
  }
  bool get(int idx) {
    int intNumber = idx >> 5;  // divide by 32
    int bitNumber = idx & 0x1F;  // mod 32
    return (_bitset[intNumber] & (1 << bitNumber)) != 0;
  }
  void set(int idx) {
    int intNumber = idx >> 5;  // divide by 32
    int bitNumber = idx & 0x1F;  // mod 32
    _bitset[intNumber] |= 1 << bitNumber;
  }
};

int main() {
  // Let's create an array with some duplicate values
  const int size = 32000;
  int array[size]{};
  int num = 1;
  for (int i = 0; i < size; i++) {
    array[i] = num;
    if (i != 781 && i != 123 && i != 17 && i != 27321) {
      num++;
    }
  }

  // Find the duplicates
  Bitset bitset(32000);

  for (int i = 0; i < size; i++) {
    if (bitset.get(array[i] - 1)) {  // -1 because bitset starts at 0, array at 1
      cout << array[i] << endl;
    } else {
      bitset.set(array[i] - 1);
    }
  }
  return 0;
}
