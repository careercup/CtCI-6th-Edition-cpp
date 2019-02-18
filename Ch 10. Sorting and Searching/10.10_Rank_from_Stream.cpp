#include <iostream>
#include <initializer_list>
using std::cout;
using std::endl;
using std::flush;
using std::initializer_list;

struct BSTNode {
  int left_size;
  BSTNode * left;
  BSTNode * right;
  int data;

  explicit BSTNode(int data) : data(data), left_size(0),
                               left(nullptr), right(nullptr) {
  }

  explicit BSTNode(initializer_list<int> l) : left_size(0),
                                              left(nullptr),
                                              right(nullptr) {
    auto begin = l.begin();
    data = *begin;
    for (initializer_list<int>::iterator it = ++begin; it != l.end(); it++) {
      insert(*it);
    }
  }

  ~BSTNode() {
    delete left;
    delete right;
  }

  void insert(int d) {
    if (d <= data) {
      if (left != nullptr) {
        left->insert(d);
      } else {
        left = new BSTNode(d);
      }
      left_size++;
    } else {
      if (right != nullptr) {
        right->insert(d);
      } else {
        right = new BSTNode(d);
      }
    }
  }

  void inorderTraversal() {
    if (left != nullptr) {
      left->inorderTraversal();
    }
    cout << data << "\t" << flush;
    if (right != nullptr) {
      right->inorderTraversal();
    }
  }

  int getRank(int d) {
    if (data == d) {
      return left_size;
    } else if (d < data) {
      if (left == nullptr) {
        return -1;
      } else {
        return left->getRank(d);
      }
    } else {
      int right_rank = right == nullptr ? -1 : right->getRank(d);
      if (right_rank == -1) {
        return -1;
      } else {
        return left_size + 1 + right_rank;
      }
    }
  }
};

int main() {
  BSTNode root({20, 15, 25, 10, 23, 5, 13, 24});

  root.inorderTraversal();
  cout << endl;
  
  cout << root.getRank(24) << endl;
  
  return 0;
}
