#include <iostream>
#include <vector>
using namespace std;


class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression
        return parent[x];
    }

    // Union by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        // Attach smaller tree under larger one
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    // Check if two elements are in the same set
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

 
int main() {
    UnionFind uf(10);  
     
    uf.unite(1, 2);
    uf.unite(2, 3);
    uf.unite(4, 5);
    uf.unite(6, 7);
    uf.unite(5, 6);

     
    cout << "Connected(1, 3): " << (uf.connected(1, 3) ? "Yes" : "No") << endl;
    cout << "Connected(1, 4): " << (uf.connected(1, 4) ? "Yes" : "No") << endl;
    cout << "Connected(4, 7): " << (uf.connected(4, 7) ? "Yes" : "No") << endl;

     uf.unite(3, 4);

     cout << "Connected(1, 5): " << (uf.connected(1, 5) ? "Yes" : "No") << endl;
    cout << "Connected(2, 7): " << (uf.connected(2, 7) ? "Yes" : "No") << endl;

    return 0;
}
