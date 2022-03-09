/*
  Dijkstra_algorithm find the shortest path in a graphy

*/

#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <utility>
# define INF 0x3f3f3f3f

using namespace std;

class Graphy{
    private:
        // the number of vertices
        // 节点个数
        int V;

        // pointer to adjacnecy list
        // 一个 pair 一个存储 节点 的值， 一个存储 边 的权重
        list<pair<int, int>> *adj;

    public:
        // constructor prototype
        Graphy(int V);

        // Medthod to  add an edge/weight pair
        void addEdge(int v1, int v2, int weight);

        // Medthod for shortest path
        void shortestPath(int s);
};

Graphy::Graphy(int v) {
    // set number of vertices
    V = v;
    
    // create a new adjacnecy list
    adj = new list<pair<int, int>>[v];
}

// implementation of method to add edges
void Graphy::addEdge(int v1, int v2, int weight) {
    adj[v1].push_back(make_pair(v2,weight));
}


// implementation of find the shortest path
void Graphy::shortestPath(int s) {
    // create a set to  store the vertices
    // use this extract the shortest path 
    set<pair<int, int >> extract_set;


    // vector for distances
    // all path are initialized to a large value 
    vector<int> distances(V, INF);

    // insert the entry point into the set
    // initialized distances to 0 
    //  0 是 起始节点， s 是节点数
    extract_set.insert(make_pair(0,s));
    // 边/ 距离 一开始赋值为 0
    distances[s] = 0;

    // continue until all the  shortest distances are finalized 
    while(!extract_set.empty()) {
        // extract the minumun distances
        pair<int, int> tmp = *(extract_set.begin());
        extract_set.erase(extract_set.begin());

        // get the vertices number
        int u = tmp.second;

        // go over the adjacnecy list
        for(auto i = adj[u].begin(); i!= adj[u].end(); i++) {
            // get the vertices and weight
            int v = (*i).first;
            int weight = (*i).second;
            
            // check if we find the shorter path to v
            if(distances[v] > distances[u] + weight) {
                // remove the current distances if it is in the set
                if(distances[v] != INF) {
                    extract_set.erase(extract_set.find(make_pair(distances[v], v)));
                }
                
                // update the distances 
                distances[v] = distances[u] + weight;
                extract_set.insert(make_pair(distances[v], v));
            }
        }
    }

    cout << "Minimum distances from vertices: " << s << endl;
    for(int i = 0; i < V; i++) {
        cout << "Vertex: " << i << "\t Distance: " << distances[i] << endl;
    }
}





int main() {
    
    // create a Graphy
    Graphy g(9);

    // give some edges and weight to the vertices

    // node 0
    g.addEdge(0,1,4);
    g.addEdge(0,7,8);


    // node 1
    g.addEdge(1,0,4);
    g.addEdge(1,2,8);
    g.addEdge(1,7,11);


    // node 2
    g.addEdge(2,1,8);
    g.addEdge(2,8,2);
    g.addEdge(2,5,4);
    g.addEdge(1,3,7);

    // node 3
    g.addEdge(2,3,7);
    g.addEdge(3,5,14);
    g.addEdge(3,4,9);


    // node 4
    g.addEdge(4,3,9);
    g.addEdge(4,5,10);


    // node 5
    g.addEdge(5,6,2);
    g.addEdge(5,2,4);
    g.addEdge(5,3,14);
    g.addEdge(5,4,10);


    // node 6
    g.addEdge(6,7,1);
    g.addEdge(6,8,6);
    g.addEdge(6,5,2);

    // node 7
    g.addEdge(7,0,8);
    g.addEdge(7,1,11);
    g.addEdge(7,8,7);
    g.addEdge(7,6,1);

    // node 8
    g.addEdge(8,2,2);
    g.addEdge(8,7,7);
    g.addEdge(8,6,6);

    g.shortestPath(0);


    return 0;

} 




