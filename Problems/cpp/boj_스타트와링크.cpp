//https://www.acmicpc.net/problem/14889
//DFS, Back Tracking

#include <iostream>
#include <vector>
#include <math.h>
#define MAX 21

using namespace std;

int n;
vector<vector<int>> mat(MAX, vector<int>(MAX, 0));
bool visited[MAX];

int result = 1e9;

void dfs(int depth, int num){
    if (depth==(n/2)){
        int start_score=0, link_score=0;
        vector<int> start, link;
        for (int i=0; i<n; i++){
            if (visited[i]) start.push_back(i);
            else link.push_back(i);
        }

        for (int i=0; i<(n/2); i++){
            for (int j=0; j<(n/2); j++){
                start_score += mat[start[i]][start[j]];
                link_score += mat[link[i]][link[j]];
            }
        }

        if (abs(start_score-link_score)<result)
            result = abs(start_score-link_score);
        return;
    }
    for (int i=num; i<n; i++){
        if (!visited[i]){
            visited[i] = true;
            dfs(depth+1, i);
            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> mat[i][j];

    dfs(0, 0);
    cout << result;
}