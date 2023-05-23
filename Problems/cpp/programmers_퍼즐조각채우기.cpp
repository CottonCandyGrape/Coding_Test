//https://school.programmers.co.kr/learn/courses/30/lessons/84021
//DFS, BFS

#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> empties;
vector<vector<pair<int, int>>> puzzles;
vector<vector<bool>> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;
int answer = 0;

vector<pair<int, int>> bfs(const vector<vector<int>>& g, int val, int s, int e){
    vector<pair<int, int>> result;
    result.push_back(make_pair(s, e));
    deque<pair<int, int>> d;
    d.push_back(make_pair(s, e));
    visited[s][e] = true;
    
    while (!d.empty()){
        int x = d.front().first;
        int y = d.front().second;
        d.pop_front();
        
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx<0 || ny<0 || nx>=n || ny>=n) continue;
            if (visited[nx][ny] || g[nx][ny]!=val) continue;
            
            visited[nx][ny] = true;
            result.push_back(make_pair(nx, ny));
            d.push_back(make_pair(nx, ny));
        }
    }
    
    return result; 
}

void zero(vector<pair<int, int>>& vec){
    int minr=n, minc=n;
    for (const auto& v : vec){
        minr = min(v.first, minr);
        minc = min(v.second, minc);
    }
    
    for (auto& v : vec){
        v.first -= minr;
        v.second -= minc;
    }
}

void rotate(vector<pair<int, int>>& v){
    int row = 0;
    for (const auto& r : v)
        row = max(r.first, row);
    
    for (int i=0; i<v.size(); i++){
        int y = v[i].first;
        int x = v[i].second;
        v[i].first = x;
        v[i].second = row-y;
    }
}

vector<vector<pair<int, int>>> getInfo(const vector<vector<int>>& g, int val){
    vector<vector<pair<int, int>>> result;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (g[i][j]==val && !visited[i][j]){
                vector<pair<int, int>> tmp = bfs(g, val, i, j);
                zero(tmp);
                result.push_back(tmp);
            }
        }
    }
    
    return result;
}

void game(){
    vector<bool> pvisited(puzzles.size(), false);
    
    for (const auto& empty : empties){
        for (int pidx=0; pidx<puzzles.size(); pidx++){
            if (pvisited[pidx]) continue;
            
            auto puzzle = puzzles[pidx];
            if (empty.size() != puzzle.size()) continue;
            
            bool flag = false;
            for (int r=0; r<4; r++){
                int k = 0; 
                
                for (int i=0; i<empty.size(); i++){
                    for (int j=0; j<puzzle.size(); j++){
                        if (empty[i].first == puzzle[j].first && empty[i].second == puzzle[j].second){
                            k++;
                            break;
                        }
                    }
                }

                if (k != empty.size()){
                    rotate(puzzle);
                    continue;
                }
                
                answer += empty.size();
                pvisited[pidx] = true;
                flag = true;
                break;
            }

            if (flag) break;
        }
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    n = game_board.size();
    
    visited.resize(n);
    fill(visited.begin(), visited.end(), vector<bool>(n, false));
    empties = getInfo(game_board, 0);
    
    fill(visited.begin(), visited.end(), vector<bool>(n, false));
    puzzles = getInfo(table, 1);

    game();

    return answer;
}