//https://school.programmers.co.kr/learn/courses/30/lessons/49189
//Dijkstra

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

vector<int> distances;
vector<vector<int>> graph;

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    distances[start] = 0;
    
    while (!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if (distances[now] < dist) continue;
        
        for (int i=0; i<graph[now].size(); i++){
            int cost = dist+1;
            int next = graph[now][i];
            if (cost < distances[next]){
                distances[next] = cost;
                pq.push(make_pair(-cost, next));
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer=0, maxv;
    distances = vector<int>(n+1, INF);
    graph = vector<vector<int>>(n+1);
    
    for (int i=0; i<edge.size(); i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    dijkstra(1);
    
    maxv = *max_element(distances.begin()+1, distances.end());
    answer = count(distances.begin()+1, distances.end(), maxv);
    
    return answer;
}