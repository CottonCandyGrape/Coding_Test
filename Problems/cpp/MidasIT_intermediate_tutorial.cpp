#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[401];
vector<pair<int, int>> distances;

void Dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    distances[start] = make_pair(0, start);

    while (!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (distances[now].first < dist) continue;

        for (int i=0; i<graph[now].size(); i++){
            int cost = dist + graph[now][i].second;
            int next = graph[now][i].first;

            if (cost < distances[next].first){
                distances[next] = make_pair(cost, now);
                pq.push(make_pair(-cost, next));
            }
            else if (cost == distances[next].first){
                distances[next].second = min(now, distances[next].second);
            }
        }
    }
}

vector<int> GetPath(int s, int e){
    vector<int> result;
    int idx = e;
    while (idx!=s){
        result.push_back(idx);
        idx = distances[idx].second;
    }
    result.push_back(idx);

    return result;
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if (a.first == b.first)
        return a.second < b.second;
    else
        return a.first > b.first;
}

vector<int> solution(int n, int m, vector<int> x, vector<int> y, vector<int> z) {
    vector<int> answer;
    vector<int> path;
    int roadNum[n+1][n+1]={};
    int traffic[m+1]={};
    vector<pair<int, int>> tvec;

    for (int i=0; i<m; i++){
        graph[x[i]].push_back(make_pair(y[i], z[i]));
        graph[y[i]].push_back(make_pair(x[i], z[i]));
        roadNum[x[i]][y[i]] = i+1;
        roadNum[y[i]][x[i]] = i+1;
    }

    for (int i=1; i<n; i++){
        distances = vector<pair<int, int>> (n+1, make_pair(INF, 0));
        Dijkstra(i);

        for (int j=i+1; j<n+1; j++){
            path.clear();
            path = GetPath(i, j);

            for (int k=0; k<path.size()-1; k++){
                int num = roadNum[path[k]][path[k+1]];
                traffic[num]++;
            }
        }
    }

    for (int i=1; i<m+1; i++)
        tvec.push_back(make_pair(traffic[i],i));
    
    sort(tvec.begin(), tvec.end(), cmp);

    for (const pair<int, int>& t : tvec)
        answer.push_back(t.second);

    return answer;
}