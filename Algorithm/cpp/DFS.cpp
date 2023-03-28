#include <iostream>
#include <vector>

using namespace std;

bool visited[9];
vector<int> graph[9];

void dfs(int x){
    visited[x] = true;
    
    for (int i=0; i<graph[x].size(); i++){
        int y = graph[x][i];
        if(!visited[y]) dfs(y);
    }
}

//graph 초기화 하는 부분 생략