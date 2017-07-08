// Random Node: You are implementing a binary search tree class from scratch, which, in addition
// to insert, find, and delete, has a method getRandomNode() which returns a random node
// from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm
// for getRandomNode, and explain how you would implement the rest of the methods.

// Tree contains all nodes in a deque. It needs to handle insert() and delete() methods.
// getRundomNode: O(1) time
// To fill tree with deque additional: + O(N) time + O(N) memory.
// To clean tree with deque additional: + O(N) time

#include <memory>
#include <deque>
#include <random>
#include <chrono>
#include <iostream>

template <typename T>
class Tree
{
public:
    Tree()
    {
        // construct a trivial random generator engine from a time-based seed:
        auto seed = std::chrono::system_clock::now().time_since_epoch().count();
        randomEngine = std::default_random_engine(seed);
    }

    class RandomNode;
    using NodePtr = std::shared_ptr<RandomNode>;

    class RandomNode
    {
    public:
        template <typename U>
        explicit RandomNode(U &&value) : v(std::forward<U>(value))
        {
        }

        const NodePtr &left() const
        {
            return childs[0];
        }
        const NodePtr &right() const
        {
            return childs[1];
        }
        const T &value() const
        {
            return v;
        }

    private:
        std::array<NodePtr, 2> childs;
        T v;
        size_t idx; // index in the Tree::nodes, used for quick deletion from Tree::nodes
        friend class Tree;
    };

    template <typename U>
    const NodePtr insert(const NodePtr &parent, U &&value, bool insertRight)
    {
        NodePtr newNode;
        if (!parent)
            rootNode = newNode = std::make_shared<RandomNode>(std::forward<U>(value));
        else
            parent->childs[insertRight ? 1 : 0] = newNode = std::make_shared<RandomNode>(std::forward<U>(value));
        newNode->idx = nodes.size();
        nodes.push_back(newNode);
        return newNode;
    }

    const NodePtr getRundomNode() const
    {
        if (nodes.size() == 0)
            return nullptr;
        else if (nodes.size() == 1)
            return rootNode;
        else
        {
            if (randomDistribution.max() != nodes.size() - 1)
                randomDistribution = std::uniform_int_distribution<size_t>(0, nodes.size() - 1);
            return nodes.at(randomDistribution(randomEngine));
        }
    }

    const NodePtr &root() const
    {
        return this->rootNode;
    }

private:
    NodePtr rootNode;
    std::deque<NodePtr> nodes;
    mutable std::default_random_engine randomEngine;
    mutable std::uniform_int_distribution<size_t> randomDistribution;
};

int main()
{
    Tree<int> tree;
    auto node = tree.insert(nullptr, 3, false); //      3
    auto left = tree.insert(node, 1, false);    //    /   \       .
    tree.insert(left, 0, false);                //   1     5
    tree.insert(left, 2, true);                 //  / \   / \     .
    auto right = tree.insert(node, 5, true);    // 0   2 4   6
    tree.insert(right, 4, false);
    tree.insert(right, 6, true);

    std::string coma;
    for (int i = 0; i < 100; ++i)
    {
        std::cout << coma << tree.getRundomNode()->value();
        if (coma.empty())
            coma = ", ";
    }
    std::cout << std::endl;
}
