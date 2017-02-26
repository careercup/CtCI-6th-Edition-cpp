// Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a
// binary search tree. You may assume that each node has a link to its parent.

#include <vector>
#include "tree.hpp"
#include "treetestutils.hpp"

template <typename T>
NodePtr<T, true> getMin(NodePtr<T, true> node)
{
    if (!node)
        return nullptr;
    while (node->getLeft())
        node = node->getLeft();
    return node;
}

template <typename T>
NodePtr<T, true> nextNode(NodePtr<T, true> node)
{
    if (!node)
        return nullptr;
    if (node->getRight())
        return getMin<T>(node->getRight());
    auto next = node->getParent();
    while (next && node == next->getRight())
    {
        // right subtree is traversed -> parent and all its childs were traversed
        node = next;
        next = next->getParent();
    }
    return next;
}

int main()
{
    // valid BST
    auto tree = TestUtils::getSampleTree<int, true>(20);
    TestUtils::printTree(tree);
    auto node = getMin<int>(tree.getRoot());
    if (node)
    {
        std::cout << node->getValue();
        for (node = nextNode<int>(node); node; node = nextNode<int>(node))
            std::cout << " --> " << node->getValue();
        std::cout << std::endl;
    }
}
