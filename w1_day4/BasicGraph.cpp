#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V;  
    vector<vector<int>> adj;  

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor])
                DFSUtil(neighbor, visited);
        }
    }

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

    void display() {
        for (int i = 0; i < V; ++i) {
            cout << i << ": ";
            for (int neighbor : adj[i])
                cout << neighbor << " ";
            cout << endl;
        }
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "Adjacency List:\n";
    g.display();

    cout << "BFS starting from vertex 0: ";
    g.BFS(0);

    cout << "DFS starting from vertex 0: ";
    g.DFS(0);

    return 0;
}
