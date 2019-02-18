#include <math.h>
#include <iostream>
#include <vector>
#include <bitset>
using std::cout;
using std::endl;
using std::flush;
using std::vector;
using std::bitset;

int getLargestIndex(vector<int> * vec, int leftIdx, int midIdx, int rightIdx) {
  int len = vec->size();
  int minInt = (1 << 31);
  // cout << static_cast<bitset<32>>(minInt) << "\t" << minInt << endl;
  
  int left  = leftIdx  < 0 || leftIdx  >= len ? minInt : vec->at(leftIdx);
  int right = rightIdx < 0 || rightIdx >= len ? minInt : vec->at(rightIdx);
  int mid   = midIdx   < 0 || midIdx   >= len ? minInt : vec->at(midIdx);

  int max = fmax(left, fmax(mid, right));

  if (max == left) {
    return leftIdx;
  } else if (max == mid) {
    return midIdx;
  } else {
    return rightIdx;
  }
}

void swapElements(vector<int> * vec, int i, int j) {
  int tmp = vec->at(i);
  vec->at(i) = vec->at(j);
  vec->at(j) = tmp;
}

void valleyPeakOptimal(vector<int> * vec) {
  for (int i = 1; i < vec->size(); i+=2) {
    int largestIndex = getLargestIndex(vec, i - 1, i, i + 1);
    swapElements(vec, i, largestIndex);
  }
}

void valleyPeakSuboptimal(vector<int> * vec) {
  sort(vec->begin(), vec->end());
  for (int i = 1; i < vec->size(); i+=2) {
    swapElements(vec, i, i - 1);
  }
}

int main() {
  vector<int> input1({9, 1, 0, 4, 8, 7});
  vector<int> input2(input1);
  
  valleyPeakSuboptimal(&input1);
  for (int i : input1) {
    cout << i << " " << flush;
  }
  cout << endl;
  valleyPeakOptimal(&input2);
  for (int i : input2) {
    cout << i << " " << flush;
  }
  cout << endl;
  return 0;
}

/*
 - The complexity of the suboptimal solution is O(n log n) because of the sorting step
 - The complexity of the optimal solution is O(n) because we only do a single pass through the vector
 */
