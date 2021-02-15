/*
 * 3.5 Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use
 * an additonal temporary stack, but you may not copy the elements into any other data struture
 * (such as an array). The stack support the following operations: push, pop, peek, and isEmpty.
 */

#include <iostream>
#include <stack>
#include <array>

/*
  Hint: Having two sorted stacks, you always have the minimum at the top of one of the stacks.

  Complexity:

  - Push: O(N)
  - Peek: O(1)
  - Pop:  O(1)

  This is what happens when we push a value (let's say 3) to a pair of sorted stacks:

      [1]                  [2]                [3]                 [4]

  +---+  +---+        +---+  +---+        +---+  +---+        +---+  +---+
  |   |  |   |        |   |  | 1 |        |   |  | 1 |        |   |  |   |
  +---+  +---+        +---+  +---+        +---+  +---+        +---+  +---+
  |   |  | 4 |        |   |  | 4 |        |   |  | 4 |        | 1 |  | 4 |
  +---+  +---+  --->  +---+  +---+  --->  +---+  +---+  --->  +---+  +---+
  | 1 |  | 7 |        |   |  | 7 |        | 3 |  | 7 |        | 3 |  | 7 |
  +---+  +---+        +---+  +---+        +---+  +---+        +---+  +---+
  | 5 |  | 8 |        | 5 |  | 8 |        | 5 |  | 8 |        | 5 |  | 8 |
  +---+  +---+        +---+  +---+        +---+  +---+        +---+  +---+

  [1] We check that our value (5) is greater that both values at the top of the stacks, so we need to reorder elements. We find the stack with less elements (optional).
  [2] Push elements from the stack with less elements to the other stack until the value at the top of the former is greater or equal our value: 3
  [3] Push our value in the stack with less elements
  [4] Push (back) the elements from the other stack to the one which had less elements

  Now we have two sorted stacks!
*/

template <typename T>
class SortedStack {
  // these meaningless names are on purpose to show the stacks have no particular responsibilities
  enum StackId { ONE, ANOTHER, SIZE };
  using StackType = std::stack<T>;

  std::array<StackType, StackId::SIZE> stacks;

  bool canPushOnStack(StackType& stack, const T& value) const {
    if (stack.empty()) {
      return true;
    }
    return value <= stack.top();
  }

  StackId getStackWithLessElements() const {
    return stacks.at(StackId::ONE).size() < stacks.at(StackId::ANOTHER).size() ? StackId::ONE : StackId::ANOTHER;
  }

  StackId getStackWithMinElement() const {
    if (isEmpty()) {
      throw std::runtime_error("Stack is empty");
    }
    if (stacks.at(StackId::ONE).empty()) {
      return StackId::ANOTHER;
    }
    if (stacks.at(StackId::ANOTHER).empty()) {
      return StackId::ONE;
    }
    return stacks.at(StackId::ONE).top() < stacks.at(StackId::ANOTHER).top() ? StackId::ONE : StackId::ANOTHER;
  }

  StackId getOtherStackId(StackId current) const {
    return current == StackId::ONE ? StackId::ANOTHER : StackId::ONE;
  }

  void sortStacksAndPush(const T& value) {
    StackId stackWithLessElementsId = getStackWithLessElements();
    auto stackWithLessElements = stacks.at(stackWithLessElementsId);
    auto theOtherStack = stacks.at(getOtherStackId(stackWithLessElementsId));

    // move (temporarily) elements from our target stack to the other stack. step 2 in diagram
    std::size_t elementsMoved = 0;
    for (; stackWithLessElements.size() && stackWithLessElements.top() < value; ++elementsMoved) {
      theOtherStack.push(stackWithLessElements.top());
      stackWithLessElements.pop();
    }

    // step 3 in diagram
    stackWithLessElements.push(value);

    // push back elements from the other stack to our target stack. step 4 in diagram
    for (; elementsMoved; --elementsMoved) {
      stackWithLessElements.push(theOtherStack.top());
      theOtherStack.pop();
    }
  }

public:

  bool isEmpty() const {
    return stacks.at(StackId::ONE).empty() && stacks.at(StackId::ANOTHER).empty();
  }

  // O(N)
  void push(T&& value) {
    if (canPushOnStack(stacks.at(StackId::ONE), value)) {
      stacks.at(StackId::ONE).push(value);
    } else if (canPushOnStack(stacks.at(StackId::ANOTHER), value)) {
      stacks.at(StackId::ANOTHER).push(value);
    } else {
      // step 1 in diagram
      sortStacksAndPush(value);
    }
  }

  // O(1)
  T& peek() const {
    StackId stackId = getStackWithMinElement();
    return stacks.at(stackId).top();
  }

  // O(1)
  T pop() {
    StackId stackId = getStackWithMinElement();
    T min = stacks.at(stackId).top();
    stacks.at(stackId).pop();
    return min;
  }
};

int main() {
  SortedStack<int> stack;
  for (auto v : {5, 10, 4, 9, 3, 3, 8, 1, 2, 2, 7, 6}) {
    std::cout << "Pushed value: " << v << std::endl;
    stack.push(std::move(v));
  }

  std::cout << std::endl;

  while (!stack.isEmpty()) {
    auto v = stack.pop();
    std::cout << "Popped value: " << v << std::endl;
  }
  return 0;
}
