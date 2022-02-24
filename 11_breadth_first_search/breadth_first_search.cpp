#include <iostream>
#include <list>
/*
 the only thing we care about is whether the ndoe is visited
 * */

using namespace std;

class Graph {
    private:
        // number of vertices
        int V;
        // pointer to adjacency(邻接) list
        // 指向相邻顶点的指针
        list<int> *adj;

    public:
        // consturctor prototype
        Graph(int v);

        // Method to add an edge
        void addEdge(int v, int w);

        // Method for BFS traversal give a source "s"
        void BFS(int s);

};

// Consturctor with number of vertices 
Graph::Graph(int v) {

    // set number of verticest 
    V = v;

    // create a new adjacency list
    adj = new list<int>[v];

}

// implementation of method to add edges
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}




// perform BFS given a start vertex 
void Graph::BFS(int s) {
    // start with all the vertex as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // create a quene for BFS
    list<int> queue;

    // starting vertex marked as visited and added to queue
    visited[s]  = true;
    queue.push_back(s);

    // continue until queue is empty
    while(!queue.empty()) {
        // get front of the queue and  remove it 
        s = queue.front();
        queue.pop_front();    

        // get all adjacency vertices from that vertex 
        cout << "Checking adjacent vertices for vertex -> " << s << endl;
        cout << endl;

        for (auto i = adj[s].begin(); i != adj[s].end(); i++) {

            // we only care about the node haven't been visited yet;
            if(!visited[*i]){
                // marked as visited
                cout << "visited and enqueue -> " << *i << endl;
                visited[*i] = true;
                // push back to check this vertexn's vertices
                queue.push_back(*i);
                cout << endl;
            }

        }
    }
}


int main() {

    // create a new  graph
    Graph g(6);

    // create some edges for the vertices 
    // connections for vertex 0
    g.addEdge(0,1);
    g.addEdge(0,2);

    // connections for vertex 1
    g.addEdge(1,0);
    g.addEdge(1,3);
    g.addEdge(1,4);

    // connections for vertex 2
    g.addEdge(2,0);
    g.addEdge(2,4);

    // connections for vertex 3
    g.addEdge(3,1);
    g.addEdge(3,4);
    g.addEdge(3,5);

    // connections for vertex 4
    g.addEdge(4,1);
    g.addEdge(4,2);
    g.addEdge(4,3);
    g.addEdge(4,5);

    // connections for vertex 5
    g.addEdge(5,3);
    g.addEdge(5,4);
    g.BFS(2);

    return 0;
}

