#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::flush;
using std::vector;

vector<int> mergeSorted(vector<int> a, vector<int> b) {
  int pa = a.size() - 1;
  int pb = b.size() - 1;
  a.resize(a.size() + b.size());
  int pi = a.size() - 1;

  while (pb >= 0) {
    if (pa >= 0 && a[pa] > b[pb]) {
      a[pi] = a[pa];
      pa--;
    } else {
      a[pi] = b[pb];
      pb--;
    }
    pi--;
  }
  return a;
}

int main() {
  vector<int> a{1, 3, 5, 8, 9, 12, 16};
  vector<int> b{0, 2, 2, 6, 10, 11};

  auto sorted = mergeSorted(a, b);
  for (int i : sorted) {
    cout << i << " " << flush;
  }
  cout << endl;
}
