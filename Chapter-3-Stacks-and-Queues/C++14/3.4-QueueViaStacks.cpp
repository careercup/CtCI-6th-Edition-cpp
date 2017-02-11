// Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.

#include <iostream>
#include "stack.hpp"

template <typename T>
class MyQueue
{
public:
    template <typename U>
    void add(U &&value)
    {
        newValues.push(std::forward<U>(value));
    }

    T peek()
    {
        if (reversed.isEmpty())
            move(newValues, reversed);
        return reversed.peek();
    }

    T remove()
    {
        if (reversed.isEmpty())
            move(newValues, reversed);
        return reversed.pop();
    }

    bool isEmpty()
    {
        return newValues.isEmpty() && reversed.isEmpty();
    }

private:
    static void move(Stack<T> &from, Stack<T> &to)
    {
        while (!from.isEmpty())
            to.push(from.pop());
    }
    Stack<T> newValues;
    Stack<T> reversed;
};

int main()
{
    MyQueue<int> queue;
    for (int i = 0; i < 10; ++i)
    {
        queue.add(i);
        std::cout << "Queued value " << i << std::endl;
    }

    for (int i = 0; i < 5; ++i)
        std::cout << "Removed value " << queue.remove() << std::endl;

    for (int i = 10; i < 15; ++i)
    {
        queue.add(i);
        std::cout << "Queued value " << i << std::endl;
    }

    while (!queue.isEmpty())
        std::cout << "Removed value " << queue.remove() << std::endl;

    return 1;
}