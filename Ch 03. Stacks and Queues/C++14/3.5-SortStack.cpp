// Sort Stack: Write a program to sort a stack such that the smallest items are on the top. You can use
// an additonal temporary stack, but you may not copy the elements into any other data struture
// (such as an array). The stack support the following operations: pop, peek, and isEmpty.

#include <iostream>
#include "stack.hpp"

template <typename T>
class SortedStack
{
public:
    SortedStack() : sorted(false)
    {
    }

    template <typename U>
    void push(U &&value)
    {
        stack.push(std::forward<U>(value));
        sorted = false;
    }

    T &peek()
    {
        sort();
        return stack.peek();
    }

    T pop()
    {
        sort();
        return stack.pop();
    }

    bool isEmpty() const
    {
        return stack.isEmpty();
    }

private:
    void sort()
    {
        if (sorted)
            return;

        Stack<T> helper;
        while (!stack.isEmpty())
        {
            T value = stack.pop();

            // Move greater than 'value' elements from 'helper' to 'stack'
            while (!helper.isEmpty() && value < helper.peek())
                stack.push(helper.pop());

            // Place 'value' above smaller element into 'helper'
            helper.push(std::move(value));
        }

        // Copy from 'helper' into 'stack' in reversed order
        while (!helper.isEmpty())
            stack.push(helper.pop());
        sorted = true;
    }

    Stack<T> stack;
    bool sorted;
};

int main()
{
    SortedStack<int> stack;
    for (auto v : {5, 10, 4, 9, 3, 3, 8, 1, 2, 2, 7, 6})
    {
        stack.push(v);
        std::cout << "Pushed value: " << v << std::endl;
    }

    std::cout << std::endl;

    while (!stack.isEmpty())
    {
        auto v = stack.pop();
        std::cout << "Popped value: " << v << std::endl;
    }
    return 0;
}