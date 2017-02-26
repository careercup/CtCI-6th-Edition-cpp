// BST Sequences: A binary search tree was created by traversing through an array from left to right
// and inserting each element. Given a binary search tree with distinct elements, print all possible
// arrays that could have led to this tree.
// EXAMPLE
// Input:   2
//        1   3
// Output: {2, 1, 3}, {2, 3, 1}

#include <deque>
#include <list>
#include <cassert>
#include "tree.hpp"
#include "treetestutils.hpp"

template <typename T>
std::list<std::deque<T>> possibleStableJoins(std::deque<T> &prefix, std::deque<T> &left, std::deque<T> &right);

template <typename T>
std::list<std::deque<T>> possibleArrays(const NodePtr<T> &root)
{
    std::list<std::deque<T>> result;
    if (!root)
    {
        result.emplace_back(); // empty is required to call cycle body at least once
        return result;
    }

    auto leftArrays = possibleArrays<T>(root->getLeft());
    auto rightArrays = possibleArrays<T>(root->getRight());

    std::deque<T> prefix;
    prefix.push_back(root->getValue());
    for (auto &left : leftArrays)
        for (auto &right : rightArrays)
        {
            auto joins = possibleStableJoins<T>(prefix, left, right);
            result.splice(result.end(), std::move(joins));
            assert(prefix.size() == 1 && prefix[0] == root->getValue());
        }
    return result;
}

template <typename T>
std::list<std::deque<T>> possibleStableJoins(std::deque<T> &prefix, std::deque<T> &left, std::deque<T> &right)
{
    std::list<std::deque<T>> result;

    if (left.empty() || right.empty())
    {
        std::deque<T> r(prefix);
        r.insert(r.end(), left.begin(), left.end());
        r.insert(r.end(), right.begin(), right.end());
        result.push_back(std::move(r));
        return result;
    }

    prefix.push_back(left.front());
    left.pop_front();
    result.splice(result.end(), possibleStableJoins(prefix, left, right));
    left.push_front(prefix.back());
    prefix.pop_back();

    prefix.push_back(right.front());
    right.pop_front();
    result.splice(result.end(), possibleStableJoins(prefix, left, right));
    right.push_front(prefix.back());
    prefix.pop_back();

    return result;
}

int main()
{
    auto tree = TestUtils::treeFromArray({5, 10, 15, 20, 25, 50, 60, 65, 70, 80});
    TestUtils::printTree(tree);
    // auto tree = TestUtils::treeFromArray({2, 3, 1});
    auto result = possibleArrays<int>(tree.getRoot());

    for (auto &array : result)
    {
        std::string sep;
        std::cout << "{";
        for (auto &n : array)
        {
            std::cout << sep << n;
            if (sep.empty())
                sep = ", ";
        }
        std::cout << "}" << std::endl;
    }
}
