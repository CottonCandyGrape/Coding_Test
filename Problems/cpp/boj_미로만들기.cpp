//https://www.acmicpc.net/problem/1347
//Implementation

#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int getDir(char dir, int cur){
    if (dir == 'R'){
        if(cur == 0) return 1;
        else if(cur == 1) return 2;
        else if(cur == 2) return 3;
        else if(cur == 3) return 0;
    }
    else if (dir == 'L'){
        if(cur == 0) return 3;
        else if(cur == 3) return 2;
        else if(cur == 2) return 1;
        else if(cur == 1) return 0;
    }

    return -1;
}

int main() {
    int n;
    string path;
    cin >> n;
    cin >> path;

    int dx[] ={1, 0, -1, 0};
    int dy[] ={0, -1, 0, 1};
    int x=50, y=50, dir=0;
    int minx=1e9, miny=1e9, maxx=-1e9, maxy=-1e9;
    int map[101][101] = {};
    map[x][y] = 1;

    for(int i=0; i<n; i++){
        int d = getDir(path[i], dir);
        if(d==-1) {
            x += dx[dir];
            y += dy[dir];
            map[x][y] = 1;
        }
        else dir = d;
    }

    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(map[i][j] == 1){
                if(minx>i) minx = i;
                if(miny>j) miny = j;
                if(maxx<i) maxx = i;
                if(maxy<j) maxy = j;
            }
        }
    }

    for(int i=minx; i<=maxx; i++){
        for(int j=miny; j<=maxy; j++){
            if(map[i][j] == 1) cout << '.';
            else cout << '#';
        }
        cout << '\n';
    }
}