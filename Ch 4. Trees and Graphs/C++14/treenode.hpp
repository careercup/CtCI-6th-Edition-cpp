#pragma once

#include <memory>

template <typename T, bool WithParent = false, bool R = WithParent>
class Node;

template <typename T, bool R>
class Node<T, false, R>
{
  public:
    using NodePtr = std::shared_ptr<Node<T, R, R>>;

    Node(T &&v) : value(std::move(v))
    {
    }

    Node(const T &v) : value(v)
    {
    }

    Node(T &&v, NodePtr) : value(std::move(v))
    {
    }

    Node(const T &v, NodePtr) : value(v)
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
    void setLeft(U &&node)
    {
        childs.first = std::forward<U>(node);
    }

    template <typename U>
    void setRight(U &&node)
    {
        childs.second = std::forward<U>(node);
    }

  protected:
    T value;
    std::pair<NodePtr, NodePtr> childs;
};

template <typename T>
class Node<T, true, true> : public Node<T, false, true>
{
  public:
    using NodePtr = std::shared_ptr<Node<T, true, true>>;

    Node(T &&v, NodePtr p) : Node<T, false, true>(std::move(v)), parent(p)
    {
    }

    Node(const T &v, NodePtr p) : Node<T, false, true>(v), parent(p)
    {
    }

    NodePtr getParent() const
    {
        return parent.lock();
    }

  protected:
    std::weak_ptr<Node<T, true, true>> parent;
};
