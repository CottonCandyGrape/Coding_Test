//https://school.programmers.co.kr/learn/courses/30/lessons/86971
//완전탐색, BFS

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visit;

int bfs(int start){
    int cnt=1;
    
    visit[start] = true;
    deque<int> dq;
    dq.push_back(start);
    
    while (!dq.empty()){
        int now = dq.front();
        dq.pop_front();
        
        for (int i=0; i<graph[now].size(); i++){
            int next=graph[now][i];
            if (!visit[next]){
                visit[next] = true;
                dq.push_back(next);
                cnt++;
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for (int i=0; i<wires.size(); i++){
        graph.clear();
        visit.clear();
        graph.resize(n+1);
        visit.resize(n+1, false);
        vector<int> tmp;
        
        for (int j=0; j<wires.size(); j++){
            if (j==i) continue;
            else{
                graph[wires[j][0]].push_back(wires[j][1]);
                graph[wires[j][1]].push_back(wires[j][0]);
            }
        }
        
        for (int k=1; k<n+1; k++){
            if (!visit[k])
                tmp.push_back(bfs(k));
        }
        
        answer = min(answer, abs(tmp[0]-tmp[1]));
    }
    
    return answer;
}