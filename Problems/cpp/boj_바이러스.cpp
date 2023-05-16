//https://www.acmicpc.net/problem/2606
//DFS, BFS

#include <iostream>
#include <vector>

using namespace std;

int n, e, cnt=0;
vector<vector<int>> graph;
vector<bool> visit;

void dfs(int start){
    cnt++;
    visit[start] = true;

    for (const int& v : graph[start]){
        if (!visit[v]){
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> e;

    graph.resize(n+1);
    visit.resize(n+1, false);
    int a, b;
    for (int i=0; i<e; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    cout << cnt-1;
}