// Validate BST: Implement a function to check if a binary tree is a binary search tree.

#include <vector>
#include "tree.hpp"
#include "treetestutils.hpp"

template <typename T>
bool checkNode(const NodePtr<T> &node, const T *minValue, const T *maxValue)
{
    if (!node)
        return true;
    if (minValue && node->getValue() <= *minValue)
        return false;
    if (maxValue && node->getValue() > *maxValue)
        return false;

    return checkNode<T>(node->getLeft(), minValue, &node->getValue()) && checkNode<T>(node->getRight(), &node->getValue(), maxValue);
}

template <typename T>
bool isValidBST(const Tree<T> &tree)
{
    return checkNode<T>(tree.getRoot(), nullptr, nullptr);
}

int main()
{
    // valid BST
    auto tree = TestUtils::getSampleTree<int>(20);
    TestUtils::printTree(tree);
    std::cout << "The tree is " << (isValidBST<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;

    // invalid BST
    tree.getRoot()->getRight()->getRight()->getRight()->setLeftChild(std::make_shared<Node<int>>(19));
    TestUtils::printTree(tree);
    std::cout << "The tree is " << (isValidBST<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;

    // invalid BST
    tree.getRoot()->getRight()->getRight()->getRight()->setLeftChild(std::make_shared<Node<int>>(15));
    TestUtils::printTree(tree);
    std::cout << "The tree is " << (isValidBST<int>(tree) ? "" : "NOT ") << "binary search tree" << std::endl;
}
