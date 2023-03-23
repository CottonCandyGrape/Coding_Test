//https://www.acmicpc.net/problem/1260
//DFS, BFS

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
int n, m, v;

void dfs(int x){
    visited[x]=true;
    cout << x << ' ';
    for (int i=0; i<graph[x].size(); i++){
        int y = graph[x][i];
        if (!visited[y]){
            dfs(y);
        }
    }
}

void bfs(int s){
    visited[s] = true;
    deque<int> q(1,s);
    cout << s << ' ';

    while(!q.empty()){
        int x = q.front(); 
        q.pop_front();

        for (int i=0; i<graph[x].size(); i++){
            int y = graph[x][i];
            if (!visited[y]){
                visited[y] = true;
                q.push_back(y);
                cout << y << ' ';
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> v;
    graph.resize(n+1);
    visited.resize(n+1);
    
    for (int i=1; i<=m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i=1; i<=n; i++)
        sort(graph[i].begin(), graph[i].end());
    
    fill(visited.begin(), visited.end(), false);
    dfs(v);
    cout << '\n';
    
    fill(visited.begin(), visited.end(), false);
    bfs(v);
}