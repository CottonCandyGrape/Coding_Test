//https://www.acmicpc.net/problem/2578
//Implementation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bingo[5][5];
bool bingoCheck[5][5] = {};

int check(){
    int cnt = 0;

    for(int i=0; i<5; i++){ //가로빙고
        bool line = true;
        for(int j=0; j<5; j++){
            if(!bingoCheck[i][j]){
                line = false;
                break;
            }
        }
        if(line) cnt++;
    }

    for(int i=0; i<5; i++){ //세로빙고
        bool line = true;
        for(int j=0; j<5; j++){
            if(!bingoCheck[j][i]){
                line = false;
                break;
            }
        }
        if(line) cnt++;
    }

    for(int k=0; k<2; k++){
        bool line =true;
        for(int i=0; i<5; i++){ //대각선빙고
            if(k==0){
                if(!bingoCheck[i][i]){
                    line = false;
                    break;
                }
            }
            else
            {
                if(!bingoCheck[i][4-i]){
                    line = false;
                    break;
                }
            }
        }
        if(line) cnt++;
    }
    
    return cnt;
}

pair<int, int> getPos(int num){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(bingo[i][j] == num) return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}

int main() {
    vector<int> nums(25);
    
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> bingo[i][j];
        }
    }

    for(int i=0; i<25; i++) cin >> nums[i];

    for(int i=0; i<25; i++){
        pair<int, int> pos = getPos(nums[i]);
        if(pos.first == -1) continue;
        bingoCheck[pos.first][pos.second] = true;
        int cnt = check();
        if(cnt >= 3) {
            cout << i+1;
            break;
        }
    }
}