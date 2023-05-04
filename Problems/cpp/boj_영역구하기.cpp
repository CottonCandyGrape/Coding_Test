//https://www.acmicpc.net/problem/2583
//BFS

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int m, n, k;
vector<vector<int>> mat;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int bfs(int i, int j){
    int cnt = 1; 
    vector<vector<bool>> visit(m, vector<bool>(n, false));
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

            if (!visit[nx][ny] && !mat[nx][ny]){
                visit[nx][ny] = true;
                mat[nx][ny] = 1;
                dq.push_back(make_pair(nx, ny));
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;
    mat = vector<vector<int>>(m, vector<int>(n, 0));
    int a, b, c, d;
    for (int i=0; i<k; i++){
        cin >> a >> b >> c >> d;

        for (int x=b; x<d; x++){
            for (int y=a; y<c; y++){
                mat[x][y] = 1;
            }
        }
    }

    int district = 0;
    vector<int> cnts; 
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (!mat[i][j]){
                district++;
                cnts.push_back(bfs(i, j));
            }
        }
    }

    sort(cnts.begin(), cnts.end());
    cout << district << '\n';
    for (const int& c : cnts)
        cout << c << ' ';
}