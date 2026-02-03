#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class Graph {
private:
    int n;
    bool directed;
    vector<vector<int>> adj;
    int edges;

    void dfsRecUtil(int v, vector<bool>& visited, vector<int>& order) const;
    bool cycleUtil(int v, vector<int>& color) const;

public:
    Graph(int n, bool directed);

    void addEdge(int u, int v);
    vector<int> neighbors(int u) const;

    int V() const;
    int E() const;

    vector<vector<int>> adjacencyMatrix() const;

    // BFS
    void BFS(int start,
             vector<int>& order,
             vector<int>& dist,
             vector<int>& parent) const;

    vector<int> shortestPathUnweighted(int s, int t) const;

    // DFS
    void DFS_recursive(int start, vector<int>& order) const;
    void DFS_iterative(int start, vector<int>& order) const;

    // Part C requirements
    vector<vector<int>> connectedComponents() const;
    bool hasCycleDirected() const;
};

#endif
