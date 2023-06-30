//https://www.acmicpc.net/problem/2644
//DFS, BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visit;
int n, x, y, m;
int answer = -1;

/*
int bfs(int start){
    visit[start] = true;
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(start, 1));

    while (!dq.empty()){
        int now = dq.front().first;
        int depth = dq.front().second;
        dq.pop_front();

        for (int i=0; i<graph[now].size(); i++){
            int node = graph[now][i];
            if (node == y) return depth;
            if (!visit[node]){
                visit[node] = true;
                dq.push_back(make_pair(node, depth+1));
            }
        }
    }
    
    return -1;
}
*/

void dfs(int depth, int start){
    if (start==y) {
        answer = depth;
        return;
    }
    
    visit[start] = true;
    for (int i=0; i<graph[start].size(); i++){
        if (!visit[graph[start][i]]){
            dfs(depth+1, graph[start][i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> x >> y >> m;

    graph.resize(n+1);
    visit.resize(n+1, false);

    int a, b;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(0, x);
    cout << answer;

    //cout << bfs(x);
}

