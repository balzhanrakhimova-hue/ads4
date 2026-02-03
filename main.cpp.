#include "Graph.h"

int main() {
    Graph g(6, false);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 5);

    // ===== BFS =====
    vector<int> order, dist, parent;
    g.BFS(0, order, dist, parent);

    cout << "BFS order: ";
    for (int v : order) cout << v << " ";
    cout << endl;

    // ===== Shortest Path =====
    vector<int> path = g.shortestPathUnweighted(0, 5);
    cout << "Shortest path 0 -> 5: ";
    for (int v : path) cout << v << " ";
    cout << endl;

    // ===== DFS Recursive =====
    vector<int> dfsRec;
    g.DFS_recursive(0, dfsRec);
    cout << "DFS recursive: ";
    for (int v : dfsRec) cout << v << " ";
    cout << endl;

    // ===== DFS Iterative =====
    vector<int> dfsIt;
    g.DFS_iterative(0, dfsIt);
    cout << "DFS iterative: ";
    for (int v : dfsIt) cout << v << " ";
    cout << endl;

    // ===== Connected Components =====
    auto components = g.connectedComponents();
    cout << "Connected components:\n";
    for (int i = 0; i < components.size(); i++) {
        cout << "Component " << i + 1 << ": ";
        for (int v : components[i]) cout << v << " ";
        cout << endl;
    }

    // ===== Cycle Detection =====
    if (g.hasCycleDirected())
        cout << "Graph contains a cycle (directed check)\n";
    else
        cout << "Graph does not contain a cycle\n";

    return 0;
}
