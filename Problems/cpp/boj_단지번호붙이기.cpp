//https://www.acmicpc.net/problem/2667
//DFS, BFS


#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int n, cnt=0;
vector<int> answer;
vector<string> mat;
vector<vector<bool>> visit;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int bfs(int i, int j){
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

            if (0>nx || 0>ny || nx>=n || ny>=n) continue;

            if (mat[nx][ny]=='1' && !visit[nx][ny]){
                cnt++;
                visit[nx][ny] = true;
                dq.push_back(make_pair(nx, ny));
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    mat.resize(n);
    visit.resize(n, vector<bool>(n, false));
    for (int i=0; i<n; i++)
        cin >> mat[i];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (mat[i][j] == '1' && !visit[i][j]){
                answer.push_back(bfs(i, j));
                cnt++;
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << cnt << '\n';
    for (const int& a : answer)
        cout << a << '\n';
}