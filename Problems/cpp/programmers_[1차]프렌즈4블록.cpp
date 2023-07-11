//https://school.programmers.co.kr/learn/courses/30/lessons/17679
//Implementation

#include <string>
#include <vector>
#include <set>

using namespace std;
int answer = 0;

bool pop_board(int m, int n, vector<string>& board){
    bool pop = false;
    set<pair<int, int>> pops;
    
    for (int i=0; i<m-1; i++){
        for (int j=0; j<n-1; j++){
            if (board[i][j]==' ') continue;
            
            if (board[i][j]==board[i+1][j] &&
                board[i][j]==board[i][j+1] && 
                board[i][j]==board[i+1][j+1]){
                pops.insert(make_pair(i, j));
                pops.insert(make_pair(i, j+1));
                pops.insert(make_pair(i+1, j));
                pops.insert(make_pair(i+1, j+1));
                pop = true;
            }
        }
    }
    
    for (auto it=pops.begin(); it!=pops.end(); it++)
        //board[it->first][it->second] = ' ';
        board[(*it).first][(*it).second] = ' ';
    
    answer += pops.size();
    
    return pop;
}

void check_board(int m, int n, vector<string>& board){
    for (int i=0; i<n; i++){
        bool flag = true;
        for (int j=m-1; j>0; j--){
            if (board[j][i]==' '){
                int idx = j;
                while (idx>-1){
                    if (board[idx][i]!=' '){
                        swap(board[idx][i], board[j][i]);
                        flag = false;
                        break;
                    }
                    idx--;
                }
                if (flag) break;
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    while (true){
        bool flag = pop_board(m, n, board);
        if (flag) check_board(m, n, board);
        else break;
    }
    
    return answer;
}