#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;
int dx[] = {0, 0, -1, 1}; // Not needed here, but okay if reused elsewhere
int dy[] = {-1, 1, 0, 0};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n); // adj[u] = {{v, weight}, ...}

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        --a; --b;
        adj[a].emplace_back(b, c); 
        // Uncomment this line if graph is undirected:
        // adj[b].emplace_back(a, c);
    }

    vector<long long> dist(n, INF);
    dist[0] = 0;

    using P = pair<long long, int>; // {distance, node}
    priority_queue<P, vector<P>, greater<>> pq;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // Skip stale entry

        for (auto &[v, wt] : adj[u]) {
            if (dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (auto d : dist) {
        if (d == INF) cout << "INF ";
        else cout << d << " ";
    }
    cout << "\n";

    return 0;
}
