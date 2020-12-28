#include "StackNode.h"

StackNode::StackNode(int data, StackNode *next)
{
  this->data = data;
  this->next = next;
  minimum = nullptr;
}
