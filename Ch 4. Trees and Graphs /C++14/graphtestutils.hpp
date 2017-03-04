#pragma once

#include "graph.hpp"

namespace TestUtils
{
    template<typename State>
    Graph<State> createGraph(std::initializer_list<std::string> projects,
                            std::initializer_list<std::array<const std::string, 2>> deps)
    {
        Graph<State> graph;
        for (auto &n : projects)
            graph.addNode(n)->state = static_cast<State>(0);
        for (auto &d : deps)
            graph[d[0]]->addChild(graph[d[1]]);
        return graph;
    }

    template <typename State>
    Graph<State> getExampleGraph()
    {
        return createGraph<State>({"0", "1", "2", "3", "4", "5", "6"},
            {{"0", "1"}, {"1", "2"}, {"2", "0"}, {"2", "3"}, {"3", "2"}, {"4", "6"}, {"5", "4"}, {"6", "5"}});
    }

    template <typename State>
    Graph<State> getExampleGraph2()
    {
        return createGraph<State>({"0", "1", "2", "3"},
            {{"0", "1"}, {"1", "2"}, {"2", "0"}, {"3", "2"}});
    }

    template <typename State>
    Graph<State> getExampleGraph3()
    {
        return createGraph<State>({"0", "1", "2", "3", "4", "5"},
            {{"0", "1"}, {"0", "4"}, {"0", "5"}, {"1", "3"}, {"1", "4"}, {"2", "1"}, {"3", "2"}, {"3", "4"}});
    }
}