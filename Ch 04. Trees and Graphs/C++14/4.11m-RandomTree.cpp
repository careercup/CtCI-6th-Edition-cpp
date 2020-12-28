// Random Node: You are implementing a binary search tree class from scratch, which, in addition
// to insert, find, and delete, has a method getRandomNode() which returns a random node
// from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm
// for getRandomNode, and explain how you would implement the rest of the methods.

// Another solution with custom node implementation for balanced tree.
// getRundomNode: O(log(N)) time
// To fill tree from sorted array: O(N) time and O(N) memory.

#include <memory>
#include <array>
#include <vector>
#include "tree.hpp"
#include "treetestutils.hpp"

template <typename T, bool>
class RandomNode;

template <typename T, bool NotUsed = false>
class RandomNode
{
public:
    using NodePtr = std::shared_ptr<RandomNode<T>>;

    RandomNode(const T &v): size(1)
    {
        value = v;
    }

    const NodePtr &getLeft() const
    {
        return childs[0];
    }

    const NodePtr &getRight() const
    {
        return childs[1];
    }

    const T &getValue() const
    {
        return value;
    }

private:
    void add(const T &v)
    {
        if (!childs[v > value])
            childs[v > value] = std::make_shared<RandomNode<T>>(v);
        else
            childs[v > value]->add(v);
        ++size;
    }

    const T &getRandom() const
    {
        return get(std::rand() % size + 1);
    }

    const T &get(size_t n) const
    {
        if (n == size)
            return value;
        else if (childs[0] && n <= childs[0]->size)
            return childs[0]->get(n);
        else
            return childs[1]->get(n - (childs[0] ? childs[0]->size : 0));
    }

    T value;
    size_t size;
    std::array<NodePtr, 2> childs;

    template <typename U>
    friend class RandomTree;
};

template <typename T>
class RandomTree : public Tree<T, false, RandomNode>
{
    using Base = Tree<T, false, RandomNode>;

public:
    const T &getRandom() const
    {
        if (!Base::root)
            throw typename Base::TreeIsEmptyException();
        return Base::root->getRandom();
    }

    void add(const T &value)
    {
        if (Base::root)
            Base::root->add(value);
        else
            Base::root = std::make_shared<RandomNode<T, false>>(value);
    }
};


int main()
{
    std::srand (unsigned(std::time(0)));
    std::vector<int> v(7) ;
    std::iota(std::begin(v), std::end(v), 0); // Fill with 0, 1, ..., nodeCount - 1.
    std::random_shuffle(std::begin(v), std::end(v), [](int i){return std::rand() % i;});

    RandomTree<int> tree;
    tree.add(v.back());
    v.pop_back();
    for (auto i : v)
        tree.add(i);

    TestUtils::printTree(tree);
    std::cout << std::endl;

    // Check distribution of rundom tree nodes
    v = std::vector<int>(v.size() + 1, 0);
    for (auto i = 0U; i < v.size() * 1000; ++i)
        ++v[tree.getRandom()];

    size_t cnt = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "Total: " << cnt << " times\n";
    std::cout << std::fixed << std::setprecision(2);
    for (auto i = 0U; i < v.size(); ++i)
        std::cout << i << ": " << 100.0 * v[i] / cnt << "%\n";
}
