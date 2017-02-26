// Route Between Nodes: Given a directed graph, design an algorithm to find out whether is a
// route between to nodes.

#include <queue>
#include <iostream>
#include <cassert>
#include "graph.hpp"
#include "graphtestutils.hpp"

enum State {Unvisited, Visiting, Visited};

// Width visiting
bool routeBetwenNodes(const Graph<State> &graph, const Node<State> &from, const Node<State> &to)
{
    if (from == to)
        return true;

    for (auto &n : graph.getNodes())
        n->state = Unvisited;

    std::queue<Node<State>> queue;

    from->state = Visiting;
    queue.push(from);

    while (!queue.empty())
    {
        Node<State> n = queue.front();
        queue.pop();
        for (auto &c : n->getAdjacent())
        {
            auto v = c.lock();
            if (v && v->state == Unvisited)
            {
                if (v == to)
                    return true;
                else
                {
                    v->state = Visiting;
                    queue.push(v);
                }
            }
        }
        n->state = Visited;
    }
    return false;
}

// Recursive visiting

bool routeBetwenNodesWalker(const Graph<State> &graph, const Node<State> &from, const Node<State> &to)
{
    if (from == to)
        return true;

    from->state = Visited;

    for (auto &c : from->getAdjacent())
    {
        auto node = c.lock();
        if (node && node->state != Visited)
        {
            if (routeBetwenNodesWalker(graph, node, to))
                return true;
        }
    }
    return false;
}

bool routeBetwenNodesR(const Graph<State> &graph, const Node<State> &from, const Node<State> &to)
{
    for (auto &n : graph.getNodes())
        n->state = Unvisited;

    return routeBetwenNodesWalker(graph, from, to);
}

bool test(const Graph<State> &graph, size_t from, size_t to)
{
    auto &fromNode = graph[from], &toNode = graph[to];
    bool result = routeBetwenNodes(graph, fromNode, toNode);
    bool resultR = routeBetwenNodesR(graph, fromNode, toNode);

    assert(result == resultR);
    std::cout << toNode->Name() << " is " << (result ? "" : "NOT ") << "reachable from " << fromNode->Name() << std::endl;
    std::cout << toNode->Name() << " is " << (resultR ? "" : "NOT ") << "reachable from " << fromNode->Name() << std::endl;
    return result;
}

void testGraph(const Graph<State> &graph)
{
    auto size = graph.getNodes().size();
    for (decltype(size) i = 0; i < size; ++i)
    {
        for (decltype(size) j = 0; j < size; ++j)
            test(graph, i, j);
        std::cout << std::endl;
    }

}

int main()
{
    testGraph(TestUtils::getExampleGraph<State>());
    testGraph(TestUtils::getExampleGraph2<State>());
    testGraph(TestUtils::getExampleGraph3<State>());
    return 0;
}
