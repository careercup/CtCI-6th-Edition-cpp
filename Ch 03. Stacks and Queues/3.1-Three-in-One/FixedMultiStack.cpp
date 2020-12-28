#include "FixedMultiStack.h"

FixedMultiStack::FixedMultiStack(int stackCapacity)
{
  this->stackCapacity = stackCapacity;
  stackArray = new int[numOfStack * stackCapacity]();
  stackCapacityUsed = new int[numOfStack]();
}

FixedMultiStack::~FixedMultiStack()
{
  delete [] stackArray;
  delete [] stackCapacityUsed;
}

void FixedMultiStack::push(int stackNum, int value)
{
  if(isFull(stackNum))
    std::cout << "Stack " << stackNum << " is full.\n";
  else
  {
    stackCapacityUsed[stackNum]++;
    stackArray[indexOfTop(stackNum)] = value;
  }
}

void FixedMultiStack::pop(int stackNum)
{
  if(isEmpty(stackNum))
    std::cout << "Stack " << stackNum << " is empty.\n";
  else
  {
    int topIndex = indexOfTop(stackNum);
    stackArray[topIndex] = 0;
    stackCapacityUsed[stackNum]--;
  }
}

int FixedMultiStack::top(int stackNum) const
{
  if(isEmpty(stackNum))
  {
    std::cout << "Stack " << stackNum << " is empty.\n";
    exit(1); //Or throw an exception.
  }
  else
    return stackArray[indexOfTop(stackNum)];
}

bool FixedMultiStack::isEmpty(int stackNum) const
{
  return (stackCapacityUsed[stackNum] == 0);
}

bool FixedMultiStack::isFull(int stackNum) const
{
  return (stackCapacityUsed[stackNum] == stackCapacity);
}

int FixedMultiStack::indexOfTop(int stackNum) const
{
  int startIndex = stackNum * stackCapacity;
  int capacity = stackCapacityUsed[stackNum];
  return (startIndex + capacity - 1);
}
