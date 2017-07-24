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

enum class States
{
    NotVisited,
    Visiting,
    Visited
};

bool buildProject(const Node<States> &node, std::list<Node<States>> &order)
{
    if (node->state == States::Visited)
        return true; // Already pushed in build order

    if (node->state == States::Visiting)
    {
        // Dependency cycle detected
        order.empty();
        return false;
    }

    node->state = States::Visiting;
    for (auto &a : node->getAdjacent())
    {
        auto prj = a.lock();
        if (prj)
            if (!buildProject(prj, order))
                return false;
    }
    node->state = States::Visited;
    order.push_front(node);
    return true;
}

std::list<Node<States>> buildOrder(const Graph<States> &graph)
{
    std::list<Node<States>> order;
    auto &projects = graph.getNodes();
    for (auto &p : projects)
        if (!buildProject(p, order))
            break;
    return order;
}

void test(const Graph<States> &graph)
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
    test(TestUtils::createGraph<States>({"a", "b", "c", "d", "e", "f"},
        {{"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}}));
    
    test(TestUtils::createGraph<States>({"a", "b", "c", "d", "e", "f", "g"},
        {{"a", "e"}, {"b", "a"}, {"b", "e"}, {"c", "a"}, {"d", "g"}, {"f", "a"}, {"f", "b"}, {"f", "c"}}));
}
