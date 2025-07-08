#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, -1, 1};  // LRUD
int dy[] = {-1, 1, 0, 0};


bool bfs(queue<pair<pair<int, int>, char>> &q, vector<vector<char>> &graph, vector<vector<int>> &vis,
         vector<vector<pair<int, int>>> &parent, vector<vector<char>> &dir, int &er, int &ec) {
    string move = "LRUD";
    int n = graph.size(), m = graph[0].size();

    while (!q.empty()) {
        auto [r, c] = q.front().first;
        char ch = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m && graph[nr][nc] == '.') {
                if (ch == 'M' && vis[nr][nc] != 1) {
                    q.push({{nr, nc}, ch});
                    vis[nr][nc] = 1;
                } else if (ch == 'A' && vis[nr][nc] == -1) {
                    q.push({{nr, nc}, ch});
                    vis[nr][nc] = 0;
                    dir[nr][nc] = move[i];
                    parent[nr][nc] = {r, c};
                    if (nr == 0 || nr == n - 1 || nc == 0 || nc == m - 1) {
                        er = nr;
                        ec = nc;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> graph(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, -1));
    vector<vector<char>> dir(n, vector<char>(m));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));

    queue<pair<pair<int, int>, char>> q;

    int sr = -1, sc = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 'A') {
                sr = i;
                sc = j;
                vis[i][j] = 0;
            } else if (graph[i][j] == 'M') {
                q.push({{i, j}, 'M'});
                vis[i][j] = 1;
            }
        }
    }

    // Early escape if 'A' is already on boundary
    if (sr == 0 || sr == n - 1 || sc == 0 || sc == m - 1) {
        cout << "YES\n0\n";
        return 0;
    }

    q.push({{sr, sc}, 'A'});

    int er = -1, ec = -1;
    if (!bfs(q, graph, vis, parent, dir, er, ec)) {
        cout << "NO\n";
        return 0;
    }

    string path = "";
    while (make_pair(er, ec) != make_pair(sr, sc)) {
        path += dir[er][ec];
        tie(er, ec) = parent[er][ec];
    }

    reverse(path.begin(), path.end());

    cout << "YES\n" << path.size() << "\n" << path << "\n";

    return 0;
}
