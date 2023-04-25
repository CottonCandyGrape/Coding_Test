//https://www.acmicpc.net/problem/2563
//Implementation

#include <iostream>

using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, answer=0;
    cin >> n;

    bool paper[101][101] = {};

    int r, c;
    for (int k=0; k<n; k++){
        cin >> r >> c;
        for (int i=r; i<r+10; i++){
            for (int j=c; j<c+10; j++){
                if (paper[i][j]) continue;
                else{
                    paper[i][j] = true;
                    answer++;
                }
            }
        }
    }

    cout << answer;
}