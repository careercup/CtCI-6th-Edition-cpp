// Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an
// algorithm to create a binary search tree with minimal height.

#include <vector>
#include "tree.hpp"

template <typename T>
NodePtr<T> subtreeFromArray(const T *array, int start, int end)
{
    if (end < start)
        return nullptr;

    int i = (start + end) / 2;
    auto node = std::make_shared<Node<T>>(array[i]);
    node->setLeftChild(subtreeFromArray(array, start, i - 1));
    node->setRightChild(subtreeFromArray(array, i + 1, end));
    return node;
}

template <typename T>
Tree<T> treeFromArray(const T *array, size_t size)
{
    Tree<T> tree;
    tree.setRoot(subtreeFromArray(array, 0, size - 1));

    return tree;
}

int main()
{
    std::vector<int> array({0});
    auto tree = treeFromArray(&array[0], array.size());
    tree.printTree();

    array = {0, 1};
    tree = treeFromArray(&array[0], array.size());
    tree.printTree();

    array = {0, 1, 2};
    tree = treeFromArray(&array[0], array.size());
    tree.printTree();

    array = {0, 1, 2, 3};
    tree = treeFromArray(&array[0], array.size());
    tree.printTree();

    array = {0, 1, 2, 3, 4};
    tree = treeFromArray(&array[0], array.size());
    tree.printTree();

    array = {0, 1, 2, 3, 4, 5};
    tree = treeFromArray(&array[0], array.size());
    tree.printTree();

    array = {0, 1, 2, 3, 4, 5, 6};
    tree = treeFromArray(&array[0], array.size());
    tree.printTree();

    array = {0, 1, 2, 3, 4, 5, 6, 7};
    tree = treeFromArray(&array[0], array.size());
    tree.printTree();

    array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    tree = treeFromArray(&array[0], array.size());
    tree.printTree();

    array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    tree = treeFromArray(&array[0], array.size());
    tree.printTree();

    array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62};
    tree = treeFromArray(&array[0], array.size());
    tree.printTree();
    return 0;
}