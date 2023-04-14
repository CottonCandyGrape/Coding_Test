#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int n, m, start;
vector<pair<int, int>> graph[100001];
int d[100001];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start}); //여기서도 최소힙으로 사용하려면 -해야하지만 0이니깐 안한것
    d[start] = 0;

    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now]<dist) continue;

        for(int i=0; i<graph[now].size(); i++){
            int cost = dist + graph[now][i].second;
            int next = graph[now][i].first;

            if (cost < d[next]){
                d[next] = cost;
                pq.push(make_pair(-cost, next));
            }
        }
    }
}

//d[] INF로 초기화
//graph 초기화 부분 생략