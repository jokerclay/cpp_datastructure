#include <iostream>
#include <list>

using namespace std;

class Graph {
    private:
        // number of vertices
        int V;

        // pointer to adjacency list
        list<int> *adj;

        // DFS recurisive helper functions
        void DFS_helper(int s, bool *visited);

    public:
        // constructor prototype
        Graph(int v);

        // Method to add an edge
        void addEdge(int v, int w);

        // Method for DFS traversal give a source "s"
        void DFS(int s);
};

Graph::Graph(int v){
    // set number of vertices
    V = v;

    // create a new adjacency list
    adj = new list<int>[v];
}

// constructor with number of vertices
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFS_helper(int s, bool *visited) {
    // mark the current ndoe as visited 
    cout << "Visiting node " << s << endl;
    visited[s] = true;

    // go though the adjacency list
    for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
        // if not visited, travel though that vertex
        if(!visited[*i]) {
            cout << "going to vectex " << *i << " from vertex " << s << endl;
            DFS_helper(*i, visited);
        }
    }
}

void Graph::DFS(int s) {
    // start with all  the  vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // beginning of recurisive call
    DFS_helper(s, visited);
}
int main() {

    // create a new tree
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);

    g.addEdge(1, 1);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.addEdge(2, 0);
    g.addEdge(2, 4);

    g.addEdge(3, 1);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.addEdge(4, 1);
    g.addEdge(4, 2);
    g.addEdge(4, 4);
    g.addEdge(4, 5);

    g.DFS(5);

    return 0;
}
