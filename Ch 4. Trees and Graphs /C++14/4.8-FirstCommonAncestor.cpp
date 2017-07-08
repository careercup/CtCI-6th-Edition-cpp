// First Common Ancestor: Design an algorithm and write code to find the first common ancestor
// of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
// necessarily a binary search tree.

// My solution is faster than one from the book. commonAncestor() or commonAncHelper() function from
// the book always recursively traverse subtrees till leafs, but my solutions does it twice rarer.
// In O-notation speeds are the same.

#include <vector>
#include "tree.hpp"
#include "treetestutils.hpp"
#include "treenodeiterator.hpp"

enum FindResult
{
    NotFound,   // node not found in subtree
    FoundLeft,  // node found in left subtree
    FoundRight, // node found in right subtree
    FoundEqual  // node is subtree root
};

template <typename T>
FindResult findNodeFrom(const NodePtr<T> &startNode, const NodePtr<T> &node)
{
    if (!startNode)
        return NotFound;
    if (startNode == node)
        return FoundEqual;
    if (findNodeFrom<T>(startNode->getLeft(), node) != NotFound)
        return FoundLeft;
    else if (findNodeFrom<T>(startNode->getRight(), node) != NotFound)
        return FoundRight;
    return NotFound;
}

template <typename T>
NodePtr<T> findCommonAncestor(const Tree<T> &tree, const NodePtr<T> &one, const NodePtr<T> &two)
{
    if (one == two)
        return one;
    
    auto startNode = tree.getRoot();

    auto firstResult = findNodeFrom<T>(startNode, one);
    if (firstResult == NotFound)
        return nullptr;
    auto secondResult = findNodeFrom<T>(startNode, two);
    if (secondResult == NotFound)
        return nullptr;

    while (firstResult == secondResult)
    {
        startNode = (firstResult == FoundLeft) ? startNode->getLeft() : startNode->getRight();
        firstResult = findNodeFrom<T>(startNode, one);
        secondResult = findNodeFrom<T>(startNode, two);
    }
    return startNode;
}

int main()
{
    auto tree = TestUtils::treeFromArray({10, 1, 12, 3, 14, 25, 16, 27, 18, 29, 10, 13, 2, 15, 4, 5, 17, 7, 19, 9});
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

    // Test nodes of different trees
    auto tree2 = TestUtils::getSampleTree<int>(7);
    auto node1 = tree.getRoot()->getLeft()->getRight();
    auto node2 = tree2.getRoot()->getRight()->getLeft();
    auto ancestor = findCommonAncestor<int>(tree, node1, node2);
    std::cout << "Nodes below are of diffent trees:\n";
    std::cout << node1->getValue() << ", " << node2->getValue() << " <-- ";
    std::cout << (ancestor ? std::to_string(ancestor->getValue()) : "NOT FOUND") << std::endl;
}
