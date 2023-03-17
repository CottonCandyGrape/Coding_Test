//https://www.acmicpc.net/problem/11724
//DFS, BFS

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m, a, b;
int visited[1001];
vector<int> graph[1001];

void bfs(int s){
    visited[s] = 1;
    deque<int> q;
    q.push_back(s);

    int now;
    while (q.size()){
        now = q.front();
        q.pop_front();

        for (int i=0; i<graph[now].size(); i++){
            int v = graph[now][i];
            if (!visited[v]){
                visited[v]=1;
                q.push_back(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int count=0;
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            bfs(i);
            count++;
        }
    }
    cout << count;
    
    return 0;
}