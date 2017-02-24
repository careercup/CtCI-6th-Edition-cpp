// List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
// at each depth (e.g., if you have a tree with depth D, you'll have D linked lists).

// This task is mostly done in the function printTree :-)

#include <list>
#include "tree.hpp"
#include "treetestutils.hpp"

template <typename T>
using ListOfDepths = std::list<std::list<NodePtr<T>>>;

template <typename T>
ListOfDepths<T> getListOfDepths(const Tree<T> &tree)
{
    ListOfDepths<T> result;

    result.emplace_back();
    auto list = &result.back();
    list->push_back(tree.getRoot());

    do
    {
        result.emplace_back();
        auto &childs = result.back();
        for (const auto &n : *list)
        {
            if (n->getLeft())
                childs.push_back(n->getLeft());
            if (n->getRight())
                childs.push_back(n->getRight());
        }
        if (childs.empty())
        {
            result.pop_back();
            break;
        }
        list = &childs;
    } while (true);

    return result;
}

template <typename T>
void printDepths(const ListOfDepths<T> &depths)
{
    std::cout << "Nodes:\n";
    int depth = 0;
    for (const auto &line : depths)
    {
        std::cout << depth << ": ";
        auto sep = "";
        for (const auto &n : line)
        {
            std::cout << sep << n->getValue();
            sep = ", ";
        }
        std::cout << std::endl;
        ++depth;
    }
    std::cout << std::endl;
}

int main()
{
    auto tree = TestUtils::getSampleTree<int>(15);
    TestUtils::printTree(tree);
    auto depths = getListOfDepths(tree);
    printDepths<int>(depths);

    tree = TestUtils::getSampleTree<int>(20);
    TestUtils::printTree(tree);
    depths = getListOfDepths(tree);
    printDepths<int>(depths);
    return 0;
}
