//https://www.acmicpc.net/problem/3085
//Implementation

#include <iostream>
#include <vector>

using namespace std;

int n, result=0; 
vector<vector<char>> mat;
int dx[] = {1, 0};
int dy[] = {0, 1};

int check(){
    int count = 0;
    vector<vector<char>> cvec;

    for (const auto& m : mat)
        cvec.push_back(m);
    
    for (int i=0; i<n; i++){
        vector<char> tmp;
        for (int j=0; j<n; j++){
            tmp.push_back(mat[j][i]);
        }
        cvec.push_back(tmp);
    }

    for (const auto& c : cvec){
        int cnt = 1;
        for (int i=0; i<c.size()-1; i++){
            if (c[i] == c[i+1])
                cnt++;
            else
                cnt = 1;
            count = max(cnt, count);
        }
        
        if (count == n) break;
    }
    
    return count; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=0; i<n; i++){
        vector<char> tmp(n, ' ');
        for (int j=0; j<n; j++){
            cin >> tmp[j];
        }
        mat.push_back(tmp);
    }
    
    for (int x=0; x<n; x++){
        for (int y=0; y<n; y++){
            for (int k=0; k<2; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (0>nx || 0>ny || n<=nx || n<=ny) continue;

                if (mat[x][y] != mat[nx][ny]){
                    swap(mat[x][y], mat[nx][ny]);
                    result = max(result, check());
                    if (result == n){
                        cout << result;
                        return 0;
                    }
                    swap(mat[x][y], mat[nx][ny]);
                }
            }
        }
    }

    cout << result;
}