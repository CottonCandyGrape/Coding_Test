//https://www.acmicpc.net/problem/1012
//DFS, BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int t, m, n, k;
vector<vector<int>> mat;
vector<vector<bool>> visit;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void bfs(int i, int j){
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

            if (0>nx || 0>ny || nx>=n || ny>=m) continue;

            if (mat[nx][ny]==1 && !visit[nx][ny]){
                visit[nx][ny] = true;
                dq.push_back(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int idx=0; idx<t; idx++){
        int cnt=0;
        cin >> m >> n >> k;
        
        mat.clear();
        visit.clear();
        mat.resize(n, vector<int>(m, 0));
        visit.resize(n, vector<bool>(m, false));
        int a, b;
        for (int i=0; i<k; i++){
            cin >> a >> b;
            mat[b][a] = 1;
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (mat[i][j] == 1 && !visit[i][j]){
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }
}