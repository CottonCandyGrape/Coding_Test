//https://www.acmicpc.net/problem/1388
//DFS, Implementation

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> mat;
int n, m, result=0;

void dfs(char a, int i, int j){
    if (a=='-'){
        j++;
        if (j>=m) return;
        else if (mat[i][j]==a){
            mat[i][j] = 0;
            dfs(a, i, j);
        }
    }
    else{
        i++;
        if (i>=n) return;
        else if (mat[i][j]==a){
            mat[i][j] = 0;
            dfs(a, i, j);
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

    string tmp;
	for (int i = 0; i < n; i++){
        cin >> tmp;
        mat.push_back(tmp);
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (mat[i][j]!=0){
                dfs(mat[i][j], i, j);
                result++;
            }
        }
    }

	cout << result;
}