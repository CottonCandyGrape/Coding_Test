//https://www.acmicpc.net/problem/2669
//Implementation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mat[101][101] = {};

int main() {
    int sx, sy, ex, ey;
    for(int i=0; i<4; i++){
        cin >> sx >> sy >> ex >> ey;
        for(int j=sx; j<ex; j++){
            for(int k=sy; k<ey; k++){
                mat[j][k] = true;
            }
        }
    }

    int cnt=0;
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(mat[i][j]) cnt++;
        }
    }

    cout << cnt;
}