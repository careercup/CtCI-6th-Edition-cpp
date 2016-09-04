#include "Stack.h"

Stack::Stack()
{
  head = nullptr;
  stackSize = 0;
}

Stack::~Stack()
{
  StackNode *discard;
  while(head != nullptr)
  {
    discard = head;
    head = head->next;
    delete discard;
  }
}

void Stack::push(int item)
{
  if(isEmpty())
  {
    head = new StackNode(item, nullptr);
    head->minimum = head;
  }
  else if(item <= head->minimum->data)
  {
    head = new StackNode(item, head);
    head->minimum = head;
  }
  else
  {
    head = new StackNode(item, head);
    head->minimum = head->next->minimum;
  }

  stackSize++;
}

void Stack::pop()
{
  if(stackSize == 0 || head == nullptr)
    return;

  StackNode *discard = head;
  head = head->next;
  delete discard;
  stackSize--;
}

int Stack::top() const
{
  //Or throw an exception
  if(stackSize == 0 || head == nullptr)
  {
    std::cout << "Stack is empty.\n";
    exit(1);
  }
  return head->data;
}

int Stack::getMinimum() const
{
  //Or throw an exception
  if(stackSize == 0 || head == nullptr)
  {
    std::cout << "Stack is empty.\n";
    exit(1);
  }
  return (head->minimum->data);
}

bool Stack::isEmpty() const
{
  return (stackSize == 0 || head == nullptr);
}

int Stack::getSize() const
{
  return stackSize;
}


