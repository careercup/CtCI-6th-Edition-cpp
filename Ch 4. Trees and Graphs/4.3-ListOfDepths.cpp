#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
  int val;
  Node *left, *right;
  
  Node(int v){
    left = null;
    right = null;
    val = v;
  }
}

void createLevelLinkedListHelper(Node root, vector<list<node>> lists,  int level) {
  if(root == null)
    return;
  list<node> list;
  
  if(lists.size() == level)
    lists.push_back(list);
  else
    list = lists[level];
    
  createLevelLinkedListHelper(root.left, lists, level+1);
  createLevelLinkedListHelper(root.right, lists, level+1);
}

vector<list<node>> createLevelLinkedList(Node root) {
  vector<list<node>> lists;
  createLevelLinkedListHelper(root, lists, 0);
  return(lists);
}

