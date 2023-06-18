//https://www.acmicpc.net/problem/11725
//DFS, BFS

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<bool> visit; //이거 없어도 tree의 값으로 if 쓸 수 있다.
vector<int> tree;
vector<vector<int>> graph;

void bfs(){
    int root = 1;
    visit[root] = true;
    deque<int> dq;
    dq.push_back(root);

    while (!dq.empty()){
        int now = dq.front();
        dq.pop_front();

        for (int i=0; i<graph[now].size(); i++){
            vector<int> node = graph[now];
            if (!visit[node[i]]){
                visit[node[i]] = true;
                tree[node[i]] = now;
                dq.push_back(node[i]);
            }
        }
    }
}

void dfs(int n){
    for (const int v : graph[n]){
        if (!tree[v]){
            tree[v] = n;
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    graph.resize(n+1);
    tree.resize(n+1);
    visit.resize(n+1);

    int a, b;
    for (int i=0; i<n-1; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //bfs();
    dfs(1);
    
    for (int i=2; i<n+1; i++)
        cout << tree[i] << '\n';
}