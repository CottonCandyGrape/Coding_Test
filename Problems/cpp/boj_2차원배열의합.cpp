//https://www.acmicpc.net/problem/2167
//Implementation, DP

#include <iostream>
#include <memory.h>

using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m;

    int mat[n+1][m+1];
    memset(mat, 0, sizeof(mat));
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> mat[i][j];
            mat[i][j] += mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }

    cin >> k;
    int rs, cs, re, ce;
    for (int i=0; i<k; i++){
        cin >> rs >> cs >> re >> ce;

        int tmp = mat[re][ce] - mat[rs-1][ce] - mat[re][cs-1] + mat[rs-1][cs-1];
        cout << tmp <<'\n';
    }
}