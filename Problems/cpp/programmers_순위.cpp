//https://school.programmers.co.kr/learn/courses/30/lessons/49191
//Floyd-Warshall

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));
    for (const auto& r : results)
        graph[r[0]][r[1]] = true;
    
    for (int k=1; k<=n; k++){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                if (graph[i][k] && graph[k][j]) graph[i][j] = true;
            }
        }
    }
    
    for (int i=1; i<=n; i++){
        int cnt = 0;
        for (int j=1; j<=n; j++)
            if (graph[i][j] || graph[j][i]) cnt++;
        
        if (cnt == n-1) answer++;
    }
    
    return answer;
}

/*
A선수가 B선수보다 실력이 좋다면 A선수는 B선수를 항상 이긴다.
 => 플로이드 워셜 힌트!
*/