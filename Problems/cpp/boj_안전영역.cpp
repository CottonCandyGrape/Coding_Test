//https://www.acmicpc.net/problem/2468
//BFS, DFS

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, minv=1e9, maxv=-1e9, result=1;
vector<vector<int>> mat;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void check(vector<vector<int>>& m, int v){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (mat[i][j]<=v)
                m[i][j] = 0;
        }
    }
}

void bfs(int i, int j, vector<vector<int>>& v){
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(i, j));
    v[i][j] = 0;

    while (!dq.empty()){
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0>nx || 0>ny || nx>=n || ny>=n) continue;

            if (v[nx][ny]==1){
                v[nx][ny] = 0;
                dq.push_back(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    mat = vector<vector<int>>(n, vector<int>(n, 0));

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> mat[i][j];
            minv = min(minv, mat[i][j]);
            maxv = max(maxv, mat[i][j]);
        }
    }

    for (int v=minv; v<maxv; v++){
        vector<vector<int>> visit(n, vector<int>(n, 1));
        check(visit, v);
        int cnt=0;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (visit[i][j]==1){
                    bfs(i, j, visit);
                    cnt++;
                }
            }
        }
        
        result = max(result, cnt);
    }

    cout << result;
}