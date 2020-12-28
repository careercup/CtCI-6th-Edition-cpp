// Paths with Sum: You are given a binary tree in which each node contains an integer value (which
// might be positive or negative). Design an algorithm to count the number of paths that sum to a
// given value. The path does not need to start or end at the root or a leaf, but it must go downwards
// (traveling only from parent nodes to child nodes).

#include <unordered_map>

#include "tree.hpp"
#include "treetestutils.hpp"

int sumsFrom(const NodePtr<int> &node, int requiredSum, int pathSum, std::unordered_map<int, int> &sums)
{
    if (!node)
        return 0;

    pathSum += node->getValue();

    // Count of paths ending here and having required sum
    int overflow = pathSum - requiredSum;
    int cnt = sums.count(overflow) ? sums.at(overflow) : 0;

    // Starting from root
    if (pathSum == requiredSum)
        ++cnt;

    sums[pathSum] += 1;
    cnt += sumsFrom(node->getLeft(), requiredSum, pathSum, sums);
    cnt += sumsFrom(node->getRight(), requiredSum, pathSum, sums);

    // Done with this node, do not use pathSum till this node anymore
    if ((sums[pathSum] -= 1) == 0)
        sums.erase(pathSum); // less memory
    return cnt;
}

int countPathsWithSum(const Tree<int> &tree, int sum)
{
        std::unordered_map<int, int> tmp;
        return sumsFrom(tree.getRoot(), sum, 0, tmp);
}

int main()
{
    auto tree = TestUtils::treeFromArray({1, -2, 3, -5, 7, -11, 13, -1, 2, -3, 5, -7, 11, -1, 2, -3, 1, -2, 3, -7});
    TestUtils::printTree(tree);

    // From sum of negative values till sum of positive values
    for (int i = -42; i <= 48; ++i)
        std::cout << "Sum " << i << " can be reached in " << countPathsWithSum(tree, i) << " paths\n";
}
