#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int search(const vector<int> &vec, int num, int left, int right) {
  int middle = (left + right) / 2;
  if (num == vec[middle]) {
    return middle;
  }
  if (left > right) {
    return -1;
  }

  // Find out which of the two halves is ordered normally
  // and then use this side to figure out which half to search
  
  if (vec[left] < vec[middle]) {                     /* left side is ordered normally */
    if (num < vec[middle] && num >= vec[left]) {
      return search(vec, num, left, middle - 1);         // search the left side
    } else {
      return search(vec, num, middle + 1, right);        // search the right side
    }
  } else if (vec[left] > vec[middle]) {              /* right side is ordered normally */
    if (num <= vec[right] && num > vec[middle]) {
      return search(vec, num, middle + 1, right);        // search right side
    } else {
      return search(vec, num, left, middle - 1);         // search left side
    }
  } else if (vec[left] == vec[middle]) {             /* one of both halves is a repitition of the same number */
    if (vec[middle] != vec[right]) {
      return search(vec, num, middle + 1, right);        // if right is different, search right
    } else {                                             // otherwise we have to search both halves
      int res = search(vec, num, left, middle - 1);
      if (res != -1) {                                   // if found in left half, return
        return res;
      } else {                                           // otherwise search also right
        return search(vec, num, middle + 1, right);
      }
    }
  }
  return -1;
}

int search(const vector<int> &vec, int num) {
  return search(vec, num, 0, vec.size() - 1);
}

int main() {
  vector<int> vec{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
  // vector<int> vec{2, 2, 2, 3, 4, 2};

  cout << search(vec, 5) << endl;
  
  return 0;
}

/*
  Time complexity O(log n) if all elements are unique
  The more repititions there are, the more often we
  have to search both halves and time complexity
  approaches O(n).
*/
