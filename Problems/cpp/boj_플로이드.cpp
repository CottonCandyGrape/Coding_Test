//https://www.acmicpc.net/problem/11404
//Folyd-Warshall

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n+1, vector<int>(n+1, INF));
    for (int i=1; i<n+1; i++){
        for (int j=1; j<n+1; j++){
            if (i==j){
                mat[i][j] = 0;
            }
        }
    }
    
    int a, b, c;
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        mat[a][b] = min(mat[a][b], c);
    }

    for (int k=1; k<n+1; k++){
        for (int i=1; i<n+1; i++){
            for (int j=1; j<n+1; j++){
                if (i==j) continue;
                mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
            }
        }
    }
    
    for (int i=1; i<n+1; i++){
        for (int j=1; j<n+1; j++){
            if (mat[i][j]==INF){
                cout << 0 << ' ';
            }
            else{
                cout << mat[i][j] << ' ';
            }
        }
        cout << '\n';
    }
}
