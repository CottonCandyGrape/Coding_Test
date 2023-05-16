//https://www.acmicpc.net/problem/18352
//Dijkstra

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

int n, m, k, s;
vector<vector<int>> graph;
vector<int> dist;

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty()){
        int d = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist[now] < d) continue;

        for (int i=0; i<graph[now].size(); i++){
            int cost = d + 1;
            int next = graph[now][i];
            if (dist[next] > cost){
                dist[next] = cost;
                pq.push(make_pair(-cost, next));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k >> s;

    graph.resize(n+1);
    dist.resize(n+1, INF);
    
    int a, b;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dijkstra(s);

    if (find(dist.begin(), dist.end(), k) != dist.end()){
        for (int i=1; i<n+1; i++){
            if (dist[i]==k)
                cout << i << '\n';
        }
    }
    else
        cout << -1;
}