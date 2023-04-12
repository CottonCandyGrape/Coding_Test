//https://school.programmers.co.kr/learn/courses/30/lessons/1844
//DFS,BFS

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int bfs(vector<vector<int>>& m){
    vector<vector<bool>> visited(m.size(), vector<bool>(m[0].size(), false));

    deque<pair<int, int>> q;
    q.push_back({0, 0});
    visited[0][0] = true;

    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop_front();

        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx<0 || ny<0 || nx>=m.size() || ny>=m[0].size()) continue;

            if (!visited[nx][ny] && m[nx][ny]==1){
                visited[nx][ny] = true;
                m[nx][ny] = m[x][y]+1;
                q.push_back(make_pair(nx, ny));
            }

            if (nx==m.size()-1 && ny==m[0].size()-1)
                return m[nx][ny];
        }
    }

    return -1;
}

int solution(vector<vector<int>> maps)
{
    return bfs(maps);
}