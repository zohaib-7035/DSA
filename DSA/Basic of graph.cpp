#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template<typename t>

class graph {
public:
    unordered_map<int, list<t>> adj;

    void add(int u, t v, bool direction) {
        adj[u].push_back(v);
        if (direction == 0) { // If it's an undirected graph
            adj[v].push_back(u);
        }
    }

    void print() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " , ";
            }
            cout << endl;
        }
    }
};

int main() {
    graph<int> g;

    // Add edges
    g.add(1, 2, 0); // Edge between 1 and 2 (undirected)
    g.add(2, 3, 0); // Edge between 2 and 3 (undirected)
    g.add(4, 3, 1); // Edge from 4 to 3 (directed)
    g.add(5, 6, 0); // Edge between 5 and 6 (undirected)

    // Print adjacency list
    cout << "Adjacency List of the Graph:" << endl;
    g.print();

    return 0;
}
