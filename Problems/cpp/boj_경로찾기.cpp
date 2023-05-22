//https://www.acmicpc.net/problem/11403
//Floyd-Warshall

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    
    vector<vector<int>> mat(n, vector<int>(n));

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }

    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (mat[i][k] && mat[k][j]) mat[i][j] = 1;
            }
        }
    }
    
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }
}