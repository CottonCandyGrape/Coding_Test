//https://www.acmicpc.net/problem/1389
//BFS

#include <bits/stdc++.h>

using namespace std;

int n, m;

int bfs(const vector<int> g[], vector<bool> v, int start){
    deque<int> d;
    d.push_back(start);
    v[start] = true;
    vector<int> num(n+1, 0);

    while (!d.empty()){
        int now = d.front();
        d.pop_front();

        for (int i=0; i<g[now].size(); i++){
            if (!v[g[now][i]]){
                d.push_back(g[now][i]);
                v[g[now][i]] = true;
                num[g[now][i]] = num[now] + 1;
            }
        }
    }

    return accumulate(num.begin(), num.end(), 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    vector<int> graph[n+1];
    vector<int> nums(n+1, 0);
    vector<bool> visited(n+1, false);

    int a, b;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i=1; i<n+1; i++)
        nums[i] = bfs(graph, visited, i);
    
    cout << min_element(nums.begin()+1, nums.end()) - nums.begin();
}