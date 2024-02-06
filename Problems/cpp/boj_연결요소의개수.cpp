//https://www.acmicpc.net/problem/11724
//DFS, BFS

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visit;

void bfs(int start){
    visit[start] = true;
    deque<int> dq;
    dq.push_back(start);

    while(!dq.empty()){
        int now = dq.front();
        dq.pop_front();

        for(int i=0; i<graph[now].size(); i++){
            if(!visit[graph[now][i]]){
                visit[graph[now][i]] = true;
                dq.push_back(graph[now][i]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;

    cin >> n >> m;
    graph.resize(n+1);
    visit.resize(n+1);

    int a, b;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<n+1; i++){
        if(!visit[i]){
            bfs(i);
            cnt++;
        }
    }
    
    cout << cnt;
}