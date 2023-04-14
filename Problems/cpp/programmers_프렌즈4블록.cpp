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
        set<pair<int, int>> plist;
        for (int i=0; i<m-1; i++){
            for (int j=0; j<n-1; j++){
                if (board[i][j]=='0') continue;
                
                if (board[i][j]==board[i+1][j] &&
                    board[i][j]==board[i][j+1] &&
                    board[i][j]==board[i+1][j+1]){
                    plist.insert(make_pair(i, j));
                    plist.insert(make_pair(i+1, j));
                    plist.insert(make_pair(i, j+1));
                    plist.insert(make_pair(i+1, j+1));
                }
            }
        }

        if (plist.empty()) break;
        
        answer += plist.size();

        for (const auto& p : plist){
            board[p.first][p.second] = '0';
        }

        for (int j=0; j<n; j++){
            for (int i=m-1; i>-1; i--){
                if (board[i][j]=='0'){
                    int x = i-1;
                    while (x>-1 && board[x][j]=='0'){
                        x--;
                    }

                    if(x>=0){
                        board[i][j] = board[x][j];
                        board[x][j] = '0';
                    }
                }
            }
        }
    }
    
    return answer;
}