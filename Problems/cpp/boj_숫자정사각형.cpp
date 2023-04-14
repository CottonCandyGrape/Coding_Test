//https://www.acmicpc.net/problem/1051
//Implementation

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int result=1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<string> mat(n);
    for (int i=0; i<n; i++){
        cin >> mat[i];
    }

    int len = min(n, m);

    for (int k=1; k<len; k++){
        for (int i=0; i<n-k; i++){
            for (int j=0; j<m-k; j++){
                if (mat[i][j]==mat[i][j+k] && mat[i][j+k]==mat[i+k][j] && mat[i+k][j]==mat[i+k][j+k]){
                    result = max(result, (k+1)*(k+1));
                }
            }
        }
    }

    cout << result;
}