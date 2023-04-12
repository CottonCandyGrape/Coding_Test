//https://school.programmers.co.kr/learn/courses/30/lessons/43162
//DFS, BFS

#include <vector>

using namespace std;

void dfs(const vector<vector<int>>& c, vector<bool>& v, int start){
    v[start] = true;
    
    for (int i=0; i<c.size(); i++){
        if (start!=i && !v[i] && c[start][i]){
            dfs(c, v, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    
    for (int i=0; i<n; i++){
        if (visited[i]) continue;
        dfs(computers, visited, i);
        answer++;
    }
    
    return answer;
}