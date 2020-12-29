#pragma once

#include <stack>
#include "tree.hpp"

template <typename Iterator, typename T, bool WithParent>
class IteratorBase
{
    using NodePtr = typename Node<T, WithParent>::NodePtr;

  public:
    IteratorBase() = default;

    IteratorBase(const NodePtr &node) : currNode(node)
    {
    }

    Iterator &operator ++ ()
    {
        auto node = currNode.lock();
        if (!node)
            currNode = NodePtr();
        else if (node->getLeft())
            currNode = node->getLeft();
        else if (node->getRight())
            currNode = node->getRight();
        else
        {
            while (node->getParent() && node == node->getParent()->getRight())
                node = node->getParent();
            currNode = node->getParent() ? node->getParent()->getRight() : node->getParent();
        }
        return *static_cast<Iterator *>(this);
    }

protected:
    std::weak_ptr<Node<T, WithParent>> currNode;
};

template <typename Iterator, typename T>
class IteratorBase<Iterator, T, false>
{
    using NodePtr = std::shared_ptr<Node<T>>;

public:
    IteratorBase() = default;

    IteratorBase(const NodePtr &node) : currNode(node)
    {
    }

    Iterator &operator ++ ()
    {
        auto node = currNode.lock();
        if (!node)
            currNode = NodePtr();
        else if (node->getLeft())
        {
            parents.emplace(node);
            currNode = node->getLeft();
        }
        else if (node->getRight())
        {
            parents.emplace(node);
            currNode = node->getRight();
        }
        else
        {
            while (!parents.empty() && node == parents.top()->getRight())
            {
                node = parents.top();
                parents.pop();
            }
            currNode = !parents.empty() ? parents.top()->getRight() : NodePtr();
        }
        return *static_cast<Iterator *>(this);
    }

protected:
    std::weak_ptr<Node<T, false>> currNode;
    std::stack<NodePtr> parents;
};

template <typename T, bool WithParent>
class Iterator : public IteratorBase<Iterator<T, WithParent>, T, WithParent>
{
    using Super = IteratorBase<Iterator<T, WithParent>, T, WithParent>;
    using NodePtr = typename Node<T, WithParent>::NodePtr;

  public:
    Iterator() = default;

    Iterator(const NodePtr &node) : Super(node)
    {
    }

    NodePtr operator * ()
    {
        return Super::currNode.lock();
    }

    bool operator != (const Iterator &rh)
    {
        return Super::currNode.lock() != rh.currNode.lock();
    }
};

template <typename T, bool WithParent, typename P>
auto begin(const Tree<T, WithParent, P> &tree)
{
    return Iterator<T, WithParent>(tree.getRoot());
}

template <typename T, bool WithParent, typename P>
auto end(const Tree<T, WithParent, P>)
{
    return Iterator<T, WithParent>();
}
