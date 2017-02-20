// Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of
// this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
// node never differ by more than one.

#include <limits>

#define INCLUDE_HELPER
#include "tree.hpp"

bool checkHeight(size_t height, size_t &minHeight, size_t &maxHeight)
{
    if (height < minHeight)
        minHeight = height;
    if (height > maxHeight)
        maxHeight = height;
    if (maxHeight - minHeight > 1)
        return false;
    return true;
}

template <typename T>
int getHeight(const NodePtr<int> &node)
{
    if (!node)
        return 0;

    int leftH = getHeight<T>(node->getLeft());
    if (leftH == -1)
        return -1;

    int rightH = getHeight<T>(node->getRight());
    if (rightH == -1)
        return -1;
    
    if (std::abs(leftH - rightH) > 1)
        return -1;
    return std::max(leftH, rightH) + 1;
}

template <typename T>
bool isTreeBalanced(const Tree<T> &tree)
{
    return getHeight<T>(tree.getRoot()) != -1;
}

int main()
{
    auto tree = treeFromArray({0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}); // balanced tree
    std::cout << "Tree is " << (isTreeBalanced<int>(tree) ? "" : "NOT ") << "balanced" << std::endl;

    auto r = tree.getRoot()->getRight();
    tree.getRoot()->getRight() = std::make_shared<Node<int>>(100); // not balanced
    std::cout << "Tree is " << (isTreeBalanced<int>(tree) ? "" : "NOT ") << "balanced" << std::endl;

    tree.getRoot()->getRight() = r; // balanced
    std::cout << "Tree is " << (isTreeBalanced<int>(tree) ? "" : "NOT ") << "balanced" << std::endl;

    tree.getRoot()->getRight().reset(); // not balanced
    std::cout << "Tree is " << (isTreeBalanced<int>(tree) ? "" : "NOT ") << "balanced" << std::endl;
    return 0;
}