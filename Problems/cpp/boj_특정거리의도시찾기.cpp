//https://www.acmicpc.net/problem/18352
//BFS, Dijkstra

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e9

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, x;
    cin >> n >> m >> k >> x;
    
    vector<int> graph[n+1];
    vector<int> distance(n+1, INF); //n+1, INF 바꿔써서 한참 해맴..

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    distance[x] = 0;

    while(!pq.empty()){
        int dist = -pq.top().first; //꼭 - 붙이기! 최대힙 -> 최소힙
        int now = pq.top().second;
        pq.pop();

        if (distance[now]<dist) continue;

        for (int i=0; i<graph[now].size(); i++){
            int cost = dist + 1;
            int node = graph[now][i];

            if (cost < distance[node]){
                distance[node] = cost;
                pq.push(make_pair(-cost, node)); //꼭 - 붙이기! 최대힙 -> 최소힙
            }
        }
    }

    if (find(distance.begin(), distance.end(), k) != distance.end()){
        for (int i=1; i<n+1; i++){
            if (distance[i]==k)
                cout << i << '\n';
        }
    }
    else
        cout << -1;
}