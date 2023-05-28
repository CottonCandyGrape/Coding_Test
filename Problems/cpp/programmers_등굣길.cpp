//https://school.programmers.co.kr/learn/courses/30/lessons/42898
//DP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> mat(n, vector<int>(m, 1));
    
    for (const auto& p : puddles){
        int x = p[1]-1;
        int y = p[0]-1;
        
        mat[x][y] = 0;
        
        if (x==0){
            for (int j=y; j<m; j++)
                mat[0][j] = 0;
        }
        
        if (y==0){
            for (int j=x; j<n; j++)
                mat[j][0] = 0;
        }
    }

    for (int i=1; i<n; i++){
        for (int j=1; j<m; j++){
            if (mat[i][j]==0) continue;
            
            mat[i][j] = (mat[i-1][j] + mat[i][j-1])%1000000007;
        }
    }
    
    
    return mat[n-1][m-1];
}