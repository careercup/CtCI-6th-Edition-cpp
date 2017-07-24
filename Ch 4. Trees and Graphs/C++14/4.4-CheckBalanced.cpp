// Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of
// this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
// node never differ by more than one.

#include <limits>
#include "tree.hpp"
#include "treetestutils.hpp"

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
    auto tree = TestUtils::getSampleTree<int>(20); // balanced tree
    std::cout << "Tree is " << (isTreeBalanced<int>(tree) ? "" : "NOT ") << "balanced" << std::endl;

    // Disconnect right subtree, the result tree is not balanced
    auto r = tree.getRoot()->getRight();
    tree.getRoot()->getRight() = std::make_shared<Node<int>>(100);
    std::cout << "Tree is " << (isTreeBalanced<int>(tree) ? "" : "NOT ") << "balanced" << std::endl;

    // Return right subtree and check if the tree is balanced again
    tree.getRoot()->getRight() = r; // balanced
    std::cout << "Tree is " << (isTreeBalanced<int>(tree) ? "" : "NOT ") << "balanced" << std::endl;
    return 0;
}
