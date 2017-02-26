// Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of
// projects, where the second project is dependent on the first project). All of a project's dependencies
// must be built before the project is. Find a build order that will allow the projects to be built. If there
// is no valid build order, return an error.
// EXAMPLE
// Input:
// projects: a, b, c, d, e, f
// dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
// Output: f, e, a, b, d, c

#include <list>
#include <iostream>

#include "graph.hpp"
#include "graphtestutils.hpp"

std::list<Node<int>> buildOrder(const Graph<int> &graph)
{
    std::list<Node<int>> order;
    auto &projects = graph.getNodes();

    for (auto &n : projects)
    {
        for (auto &c : n->getAdjacent())
            c.lock()->state++;  // skip check c.lock()
    }
    for (auto &n : projects)
        if (n->state == 0)
            order.push_back(n);

    for (auto &p : order)
    {
        for (auto &c : p->getAdjacent())
        {
            auto n = c.lock();
            if (n && (--n->state) == 0)
                order.push_back(n);
        }
    }

    if (order.size() != projects.size())
        order.clear();
    return order;
}


void test(const Graph<int> &graph)
{
    auto order = buildOrder(graph);

    const char *sep = "";
    for (auto &n : order)
    {
        std::cout << sep << n->Name();
        sep = ", ";
    }
    std::cout << std::endl;
}

int main()
{
    test(TestUtils::createGraph<int>({"a", "b", "c", "d", "e", "f"},
        {{"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}}));

    test(TestUtils::createGraph<int>({"a", "b", "c", "d", "e", "f", "g"},
        {{"a", "e"}, {"b", "a"}, {"b", "e"}, {"c", "a"}, {"d", "g"}, {"f", "a"}, {"f", "b"}, {"f", "c"}}));
}
