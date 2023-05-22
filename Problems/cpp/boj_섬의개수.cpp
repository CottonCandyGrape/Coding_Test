//https://www.acmicpc.net/problem/4963
//BFS, DFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};

int r, c;
vector<vector<int>> mat;
vector<vector<bool>> visit;

void bfs(int i, int j){
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(i, j));
    visit[i][j] = true;

    while (!dq.empty()){
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for (int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0>nx || 0>ny || r<=nx || c<=ny) continue;

            if (mat[nx][ny]==1 && visit[nx][ny]==false){
                visit[nx][ny] = true;
                dq.push_back(make_pair(nx, ny));
            }
        } 
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    vector<int> result;

    while (true){
        cin >> c >> r;
        
        if (c==0 && r==0){
            for (const int r : result)
                cout << r << '\n';
            break;
        }

        mat = vector<vector<int>>(r, vector<int>(c));
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++)
                cin >> mat[i][j];
        }

        int count=0;
        visit = vector<vector<bool>>(r, vector<bool>(c, false));
        
        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                if (mat[i][j]==1 && !visit[i][j]){
                    count++;
                    bfs(i, j);
                }
            }
        }
        
        result.push_back(count);
    }
}