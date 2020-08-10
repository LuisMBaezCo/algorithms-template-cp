template <typename T>
vector <T> dijkstra(const graph<T> &g, int start) {
    assert(0 <= start && start < g.n);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> Q;
    vector<T> dist(g.n, numeric_limits<T>::max());
    dist[start] = 0;
    Q.push({(T)0, start});
    while (!Q.empty()) {
        int to = Q.top().second; Q.pop();
        for (pair<T, int> neighbor: g.adj[to]) {
            T newCost = dist[to] + neighbor.first;
            if (newCost < dist[neighbor.second]) {
                Q.push({newCost, neighbor.second});
                dist[neighbor.second] = newCost;
            }
        }
    }
    return dist;
    // returns numeric_limits<T>::max() if there's no path
}