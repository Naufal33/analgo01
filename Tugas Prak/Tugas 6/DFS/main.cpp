#include<iostream>
#include         <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[])
{

    visited[v] = true;
    cout << v << " ";


    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}


void Graph::DFS()
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            DFSUtil(i, visited);
}

int main()
{
    Graph g(9);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 4);
    g.addEdge(3, 7);
    g.addEdge(3, 8);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 5);
    g.addEdge(4, 2);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(5, 4);
    g.addEdge(5, 3);
    g.addEdge(5, 2);
    g.addEdge(6, 5);
    g.addEdge(7, 3);
    g.addEdge(7, 8);
    g.addEdge(8, 3);
    g.addEdge(8, 7);

    cout << "Following is Depth First Traversal : \n";
    g.DFS();
}
