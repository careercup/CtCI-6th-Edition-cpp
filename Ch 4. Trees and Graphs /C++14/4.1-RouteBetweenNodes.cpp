// Route Between Nodes: Given a directed graph, design an algorithm to find out whether is a
// route between to nodes.

#include <queue>
#include <iostream>
#include <cassert>
#include "graph.hpp"

enum State {Unvisited, Visiting, Visited};

// Width visiting
bool routeBetwenNodes(Graph<State> &graph, Node<State> &from, Node<State> &to)
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

bool routeBetwenNodesWalker(Graph<State> &graph, Node<State> &from, Node<State> &to)
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

bool routeBetwenNodesR(Graph<State> &graph, Node<State> &from, Node<State> &to)
{
    for (auto &n : graph.getNodes())
        n->state = Unvisited;

    return routeBetwenNodesWalker(graph, from, to);
}

bool test(Graph<State> &graph, size_t from, size_t to)
{
    bool result = routeBetwenNodes(graph, graph[from], graph[to]);
    bool resultR = routeBetwenNodesR(graph, graph[from], graph[to]);

    assert(result == resultR);
    std::cout << to << " is " << (result ? "" : "NOT ") << "reachable from " << from << std::endl;
    std::cout << to << " is " << (resultR ? "" : "NOT ") << "reachable from " << from << std::endl;
    return result;
}

void testGraph(Graph<State> &graph)
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
    auto graph = getExampleGraph<State>();
    testGraph(graph);

    graph = getExampleGraph2<State>();
    testGraph(graph);

    graph = getExampleGraph3<State>();
    testGraph(graph);
    return 0;
}
