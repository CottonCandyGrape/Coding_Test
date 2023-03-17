//https://www.acmicpc.net/problem/1260
//DFS, BFS

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n, m, s;
int from, to;
vector<int> graph[1001];
bool visited[1001];

void dfs(int s){
    visited[s] = true;
    cout << s << " ";
    for (int i=0; i<graph[s].size(); i++){
        int now = graph[s][i];
        if (!visited[now]){
           dfs(now);
        }
    }
}

void bfs(int s){
    visited[s] = true;
    deque<int> q;
    q.push_back(s);
    
    while (q.size()){
        int now = q.front();
        q.pop_front();
        cout << now << " ";
        
        for (int i=0; i<graph[now].size(); i++){
            int y = graph[now][i];
            if (!visited[y]){
                visited[y] = true;
                q.push_back(y);
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    
    for (int i=0; i<m; i++){
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    for (int i=1; i<=n; i++)
        sort(graph[i].begin(), graph[i].end());
    
    dfs(s);
    cout << endl;

    fill_n(visited,sizeof(visited)/sizeof(bool),false);
    bfs(s);

    return 0;
}