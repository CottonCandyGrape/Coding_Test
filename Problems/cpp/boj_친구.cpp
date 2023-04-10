//https://www.acmicpc.net/problem/1058
//Floyd-Warshall

#include <algorithm>
#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    char mat[n][n];
    int graph[n][n];
    string temp;
    for (int i=0; i<n; i++){
        cin >> temp;
        for (int j=0; j<n; j++){
            if (temp[j]=='Y')
                mat[i][j] = 'Y';
            else
                mat[i][j] = 'N';
        }
    }
    
    memset(graph, 0, sizeof(graph)); //배열 0으로 초기화 꼭 해줘야함
    
    //여기서 중요한건 2다리까지만 구하는 거다!!!
    for (int k=0; k<n; k++){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (i==j) continue;
                if (mat[i][j]=='Y' || (mat[i][k]=='Y' && mat[k][j]=='Y')){
                    graph[i][j] = 1;
                }
            }
        }
    }

    int result = 0;
    for (int i=0; i<n; i++){
        int cnt = count(graph[i], graph[i]+n, 1);
        result = max(result, cnt);
    }
    
    cout << result;
}

/*
2다리까지만 구해야 하는 문제였는데 다 구하니깐 안됐었다.=> (i,i) 빼고 다 1됨.
floyd-warshall이 2다리까지만 구하는 것!
*/