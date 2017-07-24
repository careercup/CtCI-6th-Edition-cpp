// Check Subtree: Tl and T2 are two very large binary trees, with Tl much bigger than T2. Create an
// algorithm to determine if T2 is a subtree of Tl.
// A tree T2 is a subtree of Tl if there exists a node n in Tl such that the subtree of n is identical to T2.
// That is, if you cut off the tree at node n, the two trees would be identical.

// Recursive solution with Tree traversing

#include "tree.hpp"
#include "treenodeiterator.hpp"
#include "treetestutils.hpp"

template <typename T>
bool compareTrees(const NodePtr<T> &left, const NodePtr<T> &right);

template <typename T>
bool checkSubtree(const NodePtr<T> &root, const NodePtr<T> &subtreeRoot);

template <typename T>
bool checkSubtree(const Tree<T> &tree, const Tree<T> &subtree)
{
    if (!subtree.getRoot())
        return true; // empty subtree
    return checkSubtree<T>(tree.getRoot(), subtree.getRoot());
}

template <typename T>
bool compareTrees(const NodePtr<T> &left, const NodePtr<T> &right)
{
    if (!left && !right)
        return true;
    else if (!left || !right) // one tree is not finished, another already finished
        return false;
    else if (left->getValue() == right->getValue())
        return compareTrees<T>(left->getLeft(), right->getLeft()) && compareTrees<T>(left->getRight(), right->getRight());
    return false;
}

template <typename T>
bool checkSubtree(const NodePtr<T> &root, const NodePtr<T> &subtreeRoot)
{
    if (!root)
        return false;
    if (root->getValue() == subtreeRoot->getValue() && compareTrees<T>(root, subtreeRoot))
        return true;
    return checkSubtree<T>(root->getLeft(), subtreeRoot) || checkSubtree<T>(root->getRight(), subtreeRoot);
}

int main()
{
    auto left = TestUtils::getSampleTree<int>(15);
    auto right = TestUtils::getSampleTree<int>(7);
    TestUtils::printTree(right);
    std::cout << (checkSubtree<int>(left, right) ? "is subtree of\n" : "is not subtree of\n");
    TestUtils::printTree(left);

    std::cout << std::endl;
    right = TestUtils::getSampleTree<int>(8);
    TestUtils::printTree(right);
    std::cout << (checkSubtree<int>(left, right) ? "is subtree of\n" : "is not subtree of\n");
    TestUtils::printTree(left);
}