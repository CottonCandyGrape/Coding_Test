//https://www.acmicpc.net/problem/15651
//DFS, Back Tracking

#include <iostream>

using namespace std;

int n, m;
int arr[9];

void dfs(int depth){
    if (depth==m){
        for (int i=0; i<m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i=1; i<n+1; i++){
        arr[depth] = i;
        dfs(depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    dfs(0);
}