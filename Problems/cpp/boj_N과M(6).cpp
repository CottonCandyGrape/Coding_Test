//https://www.acmicpc.net/problem/15655
//DFS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> vec;
vector<int> vec2;
vector<bool> visit;

void dfs(int depth, int num){
    if (depth == m){
        for (int i=0; i<m; i++){
            cout << vec2[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i=num; i<n; i++){
        if (!visit[i]){
            visit[i] = true;
            vec2[depth] = vec[i];
            dfs(depth+1, i+1);
            visit[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vec.resize(n);
    vec2.resize(n);
    visit.resize(n, false);
    for (int i=0; i<n; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    dfs(0, 0);
}