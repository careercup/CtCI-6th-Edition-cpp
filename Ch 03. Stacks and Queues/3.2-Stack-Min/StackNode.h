#ifndef STACKNODE_H
#define STACKNODE_H

class Stack;

class StackNode
{
public:
  friend class Stack;
  StackNode(int data, StackNode *next);

private:
  int data;
  StackNode *next;
  StackNode *minimum;
};

#endif // STACKNODE_H
