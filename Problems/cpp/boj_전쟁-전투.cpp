//https://www.acmicpc.net/problem/1303
//BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;
vector<string> mat;
vector<vector<bool>> visit;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int bfs(int i, int j, char color){
    int cnt = 1; 
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(i, j));
    visit[i][j] = true;

    while (!dq.empty()){
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0>nx || 0>ny || m<=nx || n<=ny) continue;

            if (!visit[nx][ny] && mat[nx][ny]==color){
                visit[nx][ny] = true;
                dq.push_back(make_pair(nx, ny));
                cnt++;
            }
        }
    }

    return cnt*cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    mat = vector<string>(m);
    visit = vector<vector<bool>>(m, vector<bool>(n, false));
    for (int i=0; i<m; i++){
        cin >> mat[i];
    }


    int w = 0, b = 0, tmp;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (!visit[i][j]){
                tmp = bfs(i, j, mat[i][j]);

                if (mat[i][j]=='W')
                    w += tmp;
                else
                    b += tmp;
            }
        }
    }

    cout << w << ' ' << b;
}