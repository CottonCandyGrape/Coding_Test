//https://www.acmicpc.net/problem/24479
//DFS

#include <bits/stdc++.h>

using namespace std;

int n, m, s;
int cnt = 1;

void dfs(const vector<int> g[], vector<int>& v, int start){
    v[start] = cnt++;

    for (int i=0; i<g[start].size(); i++){
        if (!v[g[start][i]]) {
            dfs(g, v, g[start][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> s;

    vector<int> graph[n+1];
    vector<int> visited(n+1, 0);

    int a, b;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i=1; i<n+1; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(graph, visited, s);

    for (int i=1; i<n+1; i++){
        if (visited[i])
            cout << visited[i] << '\n';
        else
            cout << 0 << '\n';
    }
}