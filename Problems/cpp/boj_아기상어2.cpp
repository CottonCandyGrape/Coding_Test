//https://www.acmicpc.net/problem/17086
//BFS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> mat;
deque<pair<int, int>> dq;
int n, m;
int dx[] = {1,-1,0,0,1,1,-1,-1};
int dy[] = {0,0,-1,1,-1,1,-1,1};

void bfs(){
    while (!dq.empty()){
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for (int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0>nx || 0>ny || n<=nx || m<=ny) continue;

            if (mat[nx][ny]==0){
                mat[nx][ny] = mat[x][y] + 1;
                dq.push_back(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i=0; i<n; i++){
        vector<int> tmp(m);
        for (int j=0; j<m; j++){
            cin >> tmp[j];
            if (tmp[j]==1){
                dq.push_back(make_pair(i, j));
            }
        }
        mat.push_back(tmp);
    }

    bfs();
    
    int result = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            result = max(result, mat[i][j]);
        }
    }

    cout << result-1;
}