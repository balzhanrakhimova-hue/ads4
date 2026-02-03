vector<vector<int>> Graph::connectedComponents() const {
    vector<bool> visited(n, false);
    vector<vector<int>> components;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> component;
            stack<int> st;
            st.push(i);
            visited[i] = true;

            while (!st.empty()) {
                int v = st.top();
                st.pop();
                component.push_back(v);

                for (int u : adj[v]) {
                    if (!visited[u]) {
                        visited[u] = true;
                        st.push(u);
                    }
                }
            }
            components.push_back(component);
        }
    }
    return components;
}
