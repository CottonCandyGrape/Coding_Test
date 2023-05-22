//https://www.acmicpc.net/problem/1446
//DP

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, d;
    cin >> n >> d;
    
    vector<int> dist(d+1, 1e9);
    vector<vector<pair<int, int>>> graph(10001);
    int s, e, l;
    for (int i=0; i<n; i++){
        cin >> s >> e >> l;
        graph[e].push_back(make_pair(s, l));
    }

    dist[0] = 0;
    for (int i=1; i<d+1; i++){
        if (graph[i].size()==0){
            dist[i] = dist[i-1]+1;
        }
        else{
            for (int j=0; j<graph[i].size(); j++){
                int tmp = graph[i][j].first;
                dist[i] = min(dist[i], min(dist[i-1]+1, dist[tmp]+graph[i][j].second));
            }
        }
    }

    cout << dist[d];
}