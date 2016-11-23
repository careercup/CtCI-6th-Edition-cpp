// We use the topological sort to solve the build order problem. DFS is used.
#include<iostream>
#include <list>
#include <stack>
using namespace std;

// Class to represent a graph
class Graph
{
    int V;    // Number of vertices

    // Pointer to an array containing adjacency listsList
    list<int> *adj;

    // A function used by topologicalSort
    void DFS(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor

     // function to add an edge to graph
    void addEdge(int v, int w);

    // prints a Topological Sort of the complete graph
    void topologicalSort();
};

// Implement the member functions
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v¡¯s list.
}

// A recursive function used by topologicalSort
void Graph::DFS(int v, bool visited[],
                                stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited, Stack);

    // Push current vertex to stack which stores result
    Stack.push(v);
}

// The function to do Topological Sort. It uses recursive
// DFS()
void Graph::topologicalSort()
{
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        DFS(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram
    Graph g(8);                    // Graph contains 8 nodes
    g.addEdge(5, 2);               // Project 2 depends on 5
    g.addEdge(5, 0);               // Project 0 depends on 5
    g.addEdge(4, 0);               // Project 0 depends on 4
    g.addEdge(4, 1);               // Project 1 depends on 4
    g.addEdge(2, 3);               // Project 3 depends on 2
    g.addEdge(3, 1);               // Project 1 depends on 3
    g.addEdge(5, 7);               // Project 7 depends on 5
    g.addEdge(7, 6);               // Project 6 depends on 7
    g.addEdge(2, 7);               // Project 7 depends on 2

    cout << "Following is a Topological Sort (build order) of the given graph \n";
    g.topologicalSort();

    return 0;
}
