//https://www.acmicpc.net/problem/1018
//Implementation

#include <iostream>
#include <vector>

using namespace std;

vector<string> mat;
int n, m, result=1e9;

int check(int sx, int sy){
    int cnt = 0;

    for(int i=sx; i<sx+8; i++){
        for(int j=sy; j<sy+8; j++){
            if(i%2 == j%2){
                if(mat[i][j] == 'W')
                    cnt++;
            }
            else{
                if(mat[i][j] == 'B')
                    cnt++;
            }
        }
    }

    cnt = cnt>32? 64-cnt : cnt;

    return cnt;
}

int main() {
    cin >> n >> m;

    mat.resize(n);
    for(int i=0; i<n; i++) cin >> mat[i];

    for(int i=0; i<=n-8; i++){
        for(int j=0; j<=m-8; j++){
            result = min(result, check(i, j));
        }
    }

    cout << result;
}