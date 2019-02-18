#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

int sparseSearch(const vector<string> &vec, string find, int left, int right) {
  // base case
  if (left > right) {
    return -1;
  }
  
  // move middle to closest non empty string
  int middle = (left + right) / 2;
  
  if (vec[middle] == "") {
    int midL = middle - 1;
    int midR = middle + 1;
    while (true) {
      if (midL < left && midR > right) {  // only "" between left and right
        return -1;
      } else if (midL >= left && vec[midL] != "") {
        middle = midL;
        break;
      } else if (midR <= right && vec[midR] != "") {
        middle = midR;
        break;
      }
      midL--;
      midR++;
    }
  }

  // Recurse if necessary
  if (vec[middle] == find) {
    return middle;
  } else if (vec[middle] > find) {
    return sparseSearch(vec, find, left, middle - 1);
  } else {
    return sparseSearch(vec, find, middle + 1, right);
  }
}

int sparseSearch(const vector<string> &vec, string find) {
  // Treats searching for "" as an error.
  // Alternatively we could allow searching for ""
  // and return the index of the first encountered occurence.
  if (find == "") {
    return -1;
  }
  return sparseSearch(vec, find, 0, vec.size() - 1);
}

int main() {
  vector<string> inp({"", "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""});

  string find = "at";
  int idx = sparseSearch(inp, find);
  cout << "'" << find << "' found at index " << idx << endl;
  
  return 0;
}

/*
  Worst case runtime O(n) because we could have an array
  with only ""s and one single string. In this case we
  would have to check every element.
 */
