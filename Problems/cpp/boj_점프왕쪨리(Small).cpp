//https://www.acmicpc.net/problem/16173
//Implementation, BFS

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {0, 1};
int dy[] = {1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> mat[i][j]; 
        }
    }

    vector<vector<bool>> visit(n, vector<bool>(n, false));
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(0,0));
    visit[0][0] = true;

    while (!dq.empty()){
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for (int i=0; i<2; i++){
            int nx = x + (dx[i] * mat[x][y]);
            int ny = y + (dy[i] * mat[x][y]);

            if (0>nx || 0>ny || nx>=n || ny>=n) continue;

            if (!visit[nx][ny]){
                visit[nx][ny] = true;
                dq.push_back(make_pair(nx, ny));
            }

            if (mat[nx][ny]==-1){
                cout << "HaruHaru";
                return 0;
            }
        }
    }

    cout << "Hing";
    return 0;
}