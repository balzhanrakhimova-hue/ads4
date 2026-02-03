#include "Graph.h"

Graph::Graph(int n, bool directed)
    : n(n), directed(directed), adj(n), edges(0) {}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    sort(adj[u].begin(), adj[u].end());
    edges++;

    if (!directed) {
        adj[v].push_back(u);
        sort(adj[v].begin(), adj[v].end());
    }
}

vector<int> Graph::neighbors(int u) const {
    return adj[u];
}

int Graph::V() const { return n; }
int Graph::E() const { return edges; }

vector<vector<int>> Graph::adjacencyMatrix() const {
    vector<vector<int>> m(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j : adj[i])
            m[i][j] = 1;
    return m;
}

// ================= BFS =================
void Graph::BFS(int start,
                vector<int>& order,
                vector<int>& dist,
                vector<int>& parent) const {

    vector<bool> visited(n, false);
    queue<int> q;

    dist.assign(n, -1);
    parent.assign(n, -1);

    visited[start] = true;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

vector<int> Graph::shortestPathUnweighted(int s, int t) const {
    vector<int> order, dist, parent;
    BFS(s, order, dist, parent);

    vector<int> path;
    if (dist[t] == -1) return path;

    for (int v = t; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());
    return path;
}

// ================= DFS =================
void Graph::dfsRecUtil(int v, vector<bool>& visited, vector<int>& order) const {
    visited[v] = true;
    order.push_back(v);

    for (int u : adj[v])
        if (!visited[u])
            dfsRecUtil(u, visited, order);
}

void Graph::DFS_recursive(int start, vector<int>& order) const {
    vector<bool> visited(n, false);
    dfsRecUtil(start, visited, order);
}

void Graph::DFS_iterative(int start, vector<int>& order) const {
    vector<bool> visited(n, false);
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int v = st.top();
        st.pop();

        if (visited[v]) continue;
        visited[v] = true;
        order.push_back(v);

        for (auto it = adj[v].rbegin(); it != adj[v].rend(); ++it)
            if (!visited[*it])
                st.push(*it);
    }
}

// ========== Connected Components ==========
vector<vector<int>> Graph::connectedComponents() const {
    vector<bool> visited(n, false);
    vector<vector<int>> components;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> comp;
            stack<int> st;
            st.push(i);
            visited[i] = true;

            while (!st.empty()) {
                int v = st.top();
                st.pop();
                comp.push_back(v);

                for (int u : adj[v]) {
                    if (!visited[u]) {
                        visited[u] = true;
                        st.push(u);
                    }
                }
            }
            components.push_back(comp);
        }
    }
    return components;
}

// ========== Cycle Detection (Directed) ==========
bool Graph::cycleUtil(int v, vector<int>& color) const {
    color[v] = 1; // gray

    for (int u : adj[v]) {
        if (color[u] == 1) return true;
        if (color[u] == 0 && cycleUtil(u, color))
            return true;
    }

    color[v] = 2; // black
    return false;
}

bool Graph::hasCycleDirected() const {
    vector<int> color(n, 0);
    for (int i = 0; i < n; i++)
        if (color[i] == 0 && cycleUtil(i, color))
            return true;
    return false;
}
