//https://www.acmicpc.net/problem/1652
//Implementation

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> mat;

int getCount(bool isRow){
    int result=0;
    for(int i=0; i<n; i++){
        int cnt=0; 
        for(int j=0; j<n; j++){
            char c = isRow ? mat[i][j] : mat[j][i];
            if(c=='.'){
                cnt++;
            }
            else if(c=='X'){
                if(cnt>=2) result++;
                cnt=0;
            }
        }
        if(cnt>=2) result++;
    }
    
    return result;
}

int main() {
    int h=0, v=0;
    cin >> n;

    mat.resize(n);
    for(int i=0; i<n; i++) cin >> mat[i];

    h = getCount(true);
    v = getCount(false);

    cout << h << ' ' << v;
}