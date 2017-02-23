#pragma once

#include <memory>

template <typename Node, bool WithParent>
class NodeBase
{
public:
    NodeBase() = default;

    NodeBase(const std::shared_ptr<Node> &p) : parent(p)
    {
    }

    std::shared_ptr<Node> getParent()
    {
        return parent.lock();
    }
private:
    std::weak_ptr<Node> parent;
};

// Specialization for tree node containing no reference to parent 
template <typename Node>
class NodeBase<Node, false>
{
public:
    NodeBase() = default;

    NodeBase(const std::shared_ptr<Node> &)
    {
    }

private:
};

template <typename T, bool WithParent = false>
class Node : public NodeBase<Node<T, WithParent>, WithParent>
{
    using Super = NodeBase<Node, WithParent>;

public:
    using NodePtr = std::shared_ptr<Node>;

    Node(T &&v) : value(std::move(v))
    {
    }

    Node(const T &v) : value(v)
    {
    }

    Node(T &&v, const NodePtr &parent) : Super(parent), value(std::move(v))
    {
    }

    Node(const T &v, const NodePtr &parent) : Super(parent), value(v)
    {
    }

    const T &getValue() const
    {
        return value;
    }

    const NodePtr &getLeft() const
    {
        return childs.first;
    }

    NodePtr &getLeft()
    {
        return childs.first;
    }

    const NodePtr &getRight() const
    {
        return childs.second;
    }

    NodePtr &getRight()
    {
        return childs.second;
    }
    
    template <typename U>
    void setLeftChild(U &&node)
    {
        childs.first = std::forward<U>(node);
    }

    template <typename U>
    void setRightChild(U &&node)
    {
        childs.second = std::forward<U>(node);
    }

protected:
    T value;
    std::pair<NodePtr, NodePtr> childs;
};
