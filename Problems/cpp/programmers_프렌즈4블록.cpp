//https://school.programmers.co.kr/learn/courses/30/lessons/17679
//Implementation

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (true){
        set<pair<int, int>> posSet;
        
        for (int i=0; i<m-1; i++){
            for (int j=0; j<n-1; j++){
                if (board[i][j]==' ') continue;
                
                if(board[i][j] == board[i][j+1] &&
                   board[i][j] == board[i+1][j] &&
                   board[i][j] == board[i+1][j+1])  
                {
                    posSet.insert(make_pair(i, j));
                    posSet.insert(make_pair(i, j+1));
                    posSet.insert(make_pair(i+1, j));
                    posSet.insert(make_pair(i+1, j+1));
                }
            }
        }

        if(posSet.size()==0) break;
        
        answer += posSet.size();
        
        for (const auto& pos : posSet)
            board[pos.first][pos.second] = ' ';

        for(int j=0; j<n; j++){
            for (int i=m-1; i>0; i--){
                if (board[i][j]==' ')
                {
                    int idx = i-1;
                    while(idx>-1 && board[idx][j]==' ')
                        idx--;
                    
                    if(idx>=0)
                        swap(board[i][j], board[idx][j]);
                }
            }
        }
    }
    
    return answer;
}