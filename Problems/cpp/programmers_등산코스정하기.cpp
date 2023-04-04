//https://school.programmers.co.kr/learn/courses/30/lessons/118669
//최단 경로

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[50001];
vector<int> intensity(50001, INF);
vector<bool> isSummit(50001, false);

//intensity가 최소가 되어야 하니깐 최단 거리로 간다.=>dijkstra 사용.
vector<int> Dijkstra(vector<int>& start){
    vector<vector<int>> cand; //정상까지의 intensity
    priority_queue<pair<int, int>> pq;
    for (const auto& s : start){ //출입구들 동시 시작.
        pq.push(make_pair(0, s));
        intensity[s] = 0;
    }
    
    while (!pq.empty()){
        int inten = -pq.top().first;//여태까지의 intensity
        int now = pq.top().second;
        pq.pop();
        
        if (intensity[now]<inten) continue;
        
        if (isSummit[now]){// 정상이면 후보에 넣음.
            cand.push_back({inten, now});
            continue;
        }
        
        for (int i=0; i<graph[now].size(); i++){
            int cinten = graph[now][i].second;
            int next = graph[now][i].first;
            
            if (max(inten, cinten) < intensity[next]){
                intensity[next] = max(inten, cinten); //inten, cinten(intensity의 후보) 비교.
                pq.push(make_pair(-intensity[next], next));
            }
        }
    }
    
    sort(cand.begin(), cand.end());
    
    return {cand[0][1], cand[0][0]};
}


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    for (const auto& p : paths){
        graph[p[0]].push_back(make_pair(p[1], p[2]));
        graph[p[1]].push_back(make_pair(p[0], p[2]));
    }
    
    for (const auto& s : summits) isSummit[s]= true;
    
    return Dijkstra(gates);
}