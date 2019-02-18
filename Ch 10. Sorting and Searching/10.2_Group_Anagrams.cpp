#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using std::cout;
using std::flush;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::multimap;

// Solution 1 - O(n * log n) [not considering lengths of strings in vec which are sorted too]
struct AnagramComparator {
  bool operator()(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a < b;
  }
};

// Solution 2 - variation of bucket sort
void groupAnagrams(vector<string> *vec) {
  multimap<string, string> mm;

  // Put all elements in the multimap ...
  for (string s : *vec) {
    string key = s;
    sort(key.begin(), key.end());
    mm.insert(std::make_pair(key, s));
  }

  // ... and back into the vector
  int i = 0;
  for (multimap<string, string>::iterator it = mm.begin(); it != mm.end(); it++, i++) {
    (*vec)[i] = it->second;
  }
}

int main() {
  vector<string> solution1{"nana", "cat", "anna", "house", "naan", "test", "dog", "horse", "tset", "apple"};
  vector<string> solution2(solution1);
  
  cout << "Original vector of strings:" << endl;
  for (string l : solution1) {
    cout << l << " " << flush;
  }
  cout << endl << "Solution 1:" << endl;
  
  sort(solution1.begin(), solution1.end(), AnagramComparator());

  for (string l : solution1) {
    cout << l << " " << flush;
  }
  cout << endl << "Solution 2:" << endl;
  
  groupAnagrams(&solution2);
  
  for (string l : solution2) {
    cout << l << " " << flush;
  }
  cout << endl;

  return 0;
}
