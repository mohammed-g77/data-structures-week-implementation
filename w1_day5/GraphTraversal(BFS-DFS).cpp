#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V;  // Number of vertices
    vector<vector<int>> adj;

    void dfsHelper(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int u : adj[v])
            if (!visited[u])
                dfsHelper(u, visited);
    }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);   
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front(); q.pop();
            cout << v << " ";

            for (int u : adj[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        dfsHelper(start, visited);
        cout << endl;
    }
};

int main() {
     
    Graph g(6);

 
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "BFS starting from vertex 0: ";
    g.BFS(0);   

    cout << "DFS starting from vertex 0: ";
    g.DFS(0);  

    return 0;
}
