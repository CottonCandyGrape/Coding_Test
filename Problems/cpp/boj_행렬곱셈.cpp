//https://www.acmicpc.net/problem/2740
//Implementation

#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int A[n][m];

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> A[i][j];
        }
    }
    
    cin >> m >> k;
    int B[m][k];
    for (int i=0; i<m; i++){
        for (int j=0; j<k; j++){
            cin >> B[i][j];
        }
    }

    int result[n][k];
    memset(result, 0, sizeof(result));
    for (int i=0; i<n; i++){
        for (int j=0; j<k; j++){
            for (int r=0; r<m; r++){
                result[i][j] += A[i][r]*B[r][j];// 그냥 더하면 쓰레기 값에 더하기 된다.
            }
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
}