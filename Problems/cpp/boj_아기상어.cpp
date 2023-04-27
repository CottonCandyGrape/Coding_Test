//https://www.acmicpc.net/problem/16236
//Implementation, BFS

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, ate=0, ssize=2;
vector<vector<int>> mat;
pair<int, int> shark;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

vector<vector<int>> bfs(pair<int, int> start){
    int result = 1e9;
    vector<vector<int>> visit(n, vector<int>(n, 0));
    deque<pair<int, int>> dq;
    visit[start.first][start.second] = 1;
    dq.push_back(start);

    while (!dq.empty()){
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();

        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0>nx || 0>ny || n<=nx || n<=ny) continue;
            
            if (!visit[nx][ny] && mat[nx][ny]<=ssize){
                visit[nx][ny] = visit[x][y]+1;
                dq.push_back(make_pair(nx, ny));
            }
        }
    }

    return visit;
}

int find(vector<vector<int>> v){
    int result = 1e9;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (v[i][j] && mat[i][j]>0 && mat[i][j]<ssize){
                pair<int, int> tmp = make_pair(i, j);
                if (v[i][j] < result){
                    result = v[i][j];
                    shark = tmp;
                }
            }
        }
    }

    if (result==1e9)
        return 0;
    else
        return result-1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for (int i=0; i<n; i++){
        vector<int> tmp(n);
        for (int j=0; j<n; j++){
            cin >> tmp[j];
            if (tmp[j]==9){
                shark = make_pair(i, j);
                tmp[j]=0;
            }
        }
        mat.push_back(tmp);
    }

    int result = 0;
    while (true){
        int tmp = find(bfs(shark));
        
        if (tmp==0) break;
        else{
            mat[shark.first][shark.second] = 0;
            ate++;
            if (ate==ssize) {
                ssize++;
                ate = 0;
            }
            
            result += tmp;
        }
    }

    cout << result;
}