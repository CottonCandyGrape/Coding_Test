#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

void Dijkstra(const vector<pair<int, int>> g[], vector<pair<int, int>>& d, int start){
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    d[start] = make_pair(0, start);
    
    while (!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (d[now].first < dist) continue;

        for (int i=0; i<g[now].size(); i++){
            int cost = dist + g[now][i].second;
            int next = g[now][i].first;

            if (cost < d[next].first){
                d[next] = make_pair(cost, now);
                pq.push(make_pair(-cost, next));
            }
            else if(cost == d[next].first){ //사전순을 위한 조건
                d[next].second = now > d[next].second ? d[next].second : now;
            }
        }
    }
}

vector<int> GetPath(const vector<pair<int, int>>& d, int s, int e){ //경로 찾기
    vector<int> result;
    if (s==e) return result;
    
    int idx = e;
    while (idx!=s){
        result.push_back(idx);
        idx = d[idx].second;
    }
    result.push_back(s);

    return result;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b){ //교통량으로 내림차순, 도로번호로 오름차순
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

vector<int> solution(int n, int m, vector<int> x, vector<int> y, vector<int> z) {
    vector<int> answer;
    vector<pair<int, int>> graph[n+1];
    vector<pair<int, int>> distance;
    vector<int> path;
    int roadNum[n+1][n+1]={}; //노드 사이의 도로 번호 저장하는 배열
    int traffic[m+1]={}; //도로번호(=index)의 교통량 저장하는 배열
    vector<pair<int, int>> tVec; //{교통량, 도로 번호}


    for (int i=0; i<m; i++){
        graph[x[i]].push_back(make_pair(y[i], z[i]));
        graph[y[i]].push_back(make_pair(x[i], z[i]));
        roadNum[x[i]][y[i]] = i+1;
        roadNum[y[i]][x[i]] = i+1;
    }

    //모든 경로에서 교통량 체크
    for (int i=1; i<n; i++){ //시작점
        distance = vector<pair<int, int>> (n+1, make_pair(INF, 0));
        Dijkstra(graph, distance, i);
        
        
        for (int j=i+1; j<n+1; j++){ //도착점
            path.clear();
            path = GetPath(distance, i, j);
        
            for (int k=0; k<path.size()-1; k++){ //그떄의 교통량 체크
                int num = roadNum[path[k]][path[k+1]];
                traffic[num]++;
            }        
        }
    }
    
    for (int i=1; i<m+1; i++){
        tVec.push_back(make_pair(traffic[i], i));
    }
    sort(tVec.begin(), tVec.end(), cmp);

    for (const pair<int,int>& t : tVec) //정렬 후 도로 번호만 저장.
        answer.push_back(t.second);

    return answer;
}