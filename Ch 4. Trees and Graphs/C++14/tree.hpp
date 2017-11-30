#pragma once

#include "treenode.hpp"

template <typename T, bool WithParent = false,
          template<typename, bool> class N = Node>
class Tree
{
public:
    using NodePtr = typename N<T, WithParent>::NodePtr;

    const NodePtr &getRoot() const
    {
        if (isEmpty())
            throw TreeIsEmptyException();
        return root;
    }

    template <typename U>
    void setRoot(U &&node)
    {
        root = std::forward<U>(node);
    }

    bool isEmpty() const
    {
        return !root;
    }

    class TreeIsEmptyException {};
    
protected:
    NodePtr root;
};

template <typename T, bool WithParent = false>
using NodePtr = typename Tree<T, WithParent>::NodePtr;
