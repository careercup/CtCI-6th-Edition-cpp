// Stack of Plates
// FOLLOW UP
// Implement a function popAt(int index) which performs pop operation on a specified sub-stack.

#include <iostream>
#include <deque>

template <typename T, size_t Capacity>
class SetOfStacks
{
public:
    template<typename U>
    void push(U &&value)
    {
        if (stacks.empty() || stacks.back().size() >= Capacity)
            stacks.emplace_back(1, std::forward<U>(value));
        else
            stacks.back().push_back(std::forward<U>(value));
    }

    T &peek()
    {
        return stacks.back().back();
    }

    T pop()
    {
        T value = stacks.back().back();
        stacks.back().pop_back();
        if (stacks.back().empty())
            stacks.pop_back();
        return value;
    }

    // O(N)
    T popAt(int index)
    {
        if (index < 0 || index >= stacks.size())
            throw OutOfIndexException();
        T value = stacks[index].back();
        stacks[index].pop_back();
        shiftLeftTo(index);
        return value;
    }

    // Number of used limited stacks
    size_t size() const
    {
        return stacks.size();
    }

    class OutOfIndexException
    {
    };


private:

    void shiftLeftTo(int index)
    {
        if (index == stacks.size() - 1)
        {
            // last stack
            if (stacks.back().empty())
                stacks.pop_back();
        }
        else
        {
            stacks[index].push_back(stacks[index + 1].front());
            stacks[index + 1].pop_front();
            shiftLeftTo(index + 1);
        }
    }

    std::deque<std::deque<T>> stacks;
};

// Special case if capacity is 1. In this case popAt(int index) makes a specified sub-stack empty,
// it should be then removed instead of shifting left values.
template <typename T>
class SetOfStacks<T, 1>
{
public:
    template<typename U>
    void push(U &&value)
    {
        stacks.push_back(std::forward<T>(value));
    }

    T &peek()
    {
        return stacks.at(stacks.size() - 1);
    }

    T pop()
    {
        T value = stacks.back();
        stacks.pop_back();
        return value;
    }

    T popAt(int index)
    {
        if (index < 0 || index >= stacks.size())
            throw OutOfIndexException();
        T value = stacks.at(index);
        stacks.erase(stacks.begin() + index);
        return value;
    }

    size_t size() const
    {
        return stacks.size();
    }

    class OutOfIndexException
    {
    };


private:

    void shiftLeftTo(int index)
    {
        if (index == stacks.size() - 1)
        {
            // last stack
            if (stacks.back().empty())
                stacks.pop_back();
        }
        else
        {
            stacks[index].push_back(stacks[index + 1].front());
            stacks[index + 1].pop_front();
            shiftLeftTo(index + 1);
        }
    }

    std::deque<T> stacks;
};


// Forbid capacity 0
template <typename T>
class SetOfStacks<T, 0>
{
public:
    SetOfStacks() = delete;
};

int main()
{
    SetOfStacks<int, 2> stack;
    for (int i = 0; i < 13; ++i)
    {
        stack.push(i);
        std::cout << i << " is pushed into the stack " << stack.size() << std::endl;
    }

    std::cout << std::endl;
    stack.popAt(4);
    stack.popAt(4);

    while (stack.size() != 0)
    {
        size_t stackNo = stack.size();
        std::cout << stack.pop() << " is popped from the stack " << stackNo << std::endl;
    }

    std::cout << std::endl;

    SetOfStacks<int, 1> stack1;
    for (int i = 0; i < 13; ++i)
    {
        stack1.push(i);
        std::cout << i << " is pushed into the stack " << stack1.size() << std::endl;
    }

    std::cout << std::endl;
    stack1.popAt(4);
    stack1.popAt(4);

    while (stack1.size() != 0)
    {
        size_t stackNo = stack1.size();
        std::cout << stack1.pop() << " is popped from the stack " << stackNo << std::endl;
    }
    return 0;
}
