#pragma once

#include <stack>
#include <memory>

template <typename Iterator, typename T, bool NodeWithParent,
          template <typename, bool> class Node>
class IteratorBase
{
    using NodePtr = typename Node<T, NodeWithParent>::NodePtr;

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
    std::weak_ptr<Node<T, NodeWithParent>> currNode;
};

template <typename Iterator, typename T, template <typename, bool> class Node>
class IteratorBase<Iterator, T, false, Node>
{
    using NodePtr = std::shared_ptr<Node<T, false>>;

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

template <typename T, bool NodeWithParent, template <typename, bool> class Node>
class Iterator : public IteratorBase<Iterator<T, NodeWithParent, Node>, T, NodeWithParent, Node>
{
    using Super = IteratorBase<Iterator<T, NodeWithParent, Node>, T, NodeWithParent, Node>;
    using NodePtr = typename Node<T, NodeWithParent>::NodePtr;

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

template <typename T, bool NodeWithParent, template <typename, bool> class Node>
class Tree;

template <typename T, bool NodeWithParent, template <typename, bool> class Node>
auto begin(const Tree<T, NodeWithParent, Node> &tree)
{
    return Iterator<T, NodeWithParent, Node>(tree.getRoot());
}

template <typename T, bool NodeWithParent, template <typename, bool> class Node>
auto end(const Tree<T, NodeWithParent, Node>)
{
    return Iterator<T, NodeWithParent, Node>();
}
