//https://school.programmers.co.kr/learn/courses/30/lessons/87946
//완전탐색, DFS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = -1;
vector<bool> visit;
vector<vector<int>> d;

void dfs(int p, int depth){
    for (int i=0; i<d.size(); i++){
        if (!visit[i] && p>=d[i][0]){
            visit[i] = true;
            dfs(p-d[i][1], depth+1);
            visit[i] = false;
        }
    }
    
    answer = max(answer, depth);
}

int solution(int k, vector<vector<int>> dungeons) {
    visit = vector<bool>(dungeons.size(), false);
    d = dungeons;
    
    dfs(k, 0);
    
    return answer;
}