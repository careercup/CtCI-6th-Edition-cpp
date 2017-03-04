// First Common Ancestor: Design an algorithm and write code to find the first common ancestor
// of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
// necessarily a binary search tree.
// New condition: tree nodes contain links to their parents.

#include "tree.hpp"
#include "treetestutils.hpp"
#include "treenodeiterator.hpp"

template <typename T>
int getDepth(const Tree<T, true> &tree, NodePtr<T, true> node)
{
    size_t depth = 0;
    if (node)
    {
        while (node->getParent())
        {
            node = node->getParent();
            ++depth;
        }
    }
    // Check if the node is in this tree
    if (node != tree.getRoot())
        depth =  -1;
    return depth;
}

template <typename T>
NodePtr<T, true> findCommonAncestor(const Tree<T, true> &tree, NodePtr<T, true> one, NodePtr<T, true> two)
{
    if (one == two)
        return one;

    auto depthL = getDepth(tree, one);
    auto depthR = getDepth(tree, two);
    if (depthL == -1 || depthR == -1)
        return nullptr;

    if (depthL > depthR)
    {
        std::swap(depthL, depthR);
        std::swap(one, two); // that is why we pass 'one' and 'two' arguments by values
    }

    while (depthR != depthL)
    {
        two = two->getParent();
        --depthR;
    }
    while (one != two)
    {
        one = one->getParent();
        two = two->getParent();
    }
    return one;
}

int main()
{
    auto tree = TestUtils::treeFromArray<int, true>({10, 1, 12, 3, 14, 25, 16, 27, 18, 29, 10, 13, 2, 15, 4, 5, 17, 7, 19, 9});
    TestUtils::printTree(tree);

    for (auto one : tree)
    {
        if (one == tree.getRoot())
            continue; // it is not interesting
        for (auto two : tree)
        {
            if (two == tree.getRoot() || two == one)
                continue; // it is not interesting
            auto ancestor = findCommonAncestor<int>(tree, one, two);
            std::cout << one->getValue() << ", " << two->getValue() << " <-- ";
            std::cout << (ancestor ? std::to_string(ancestor->getValue()) : "NOT FOUND") << std::endl;
        }
    }
}
