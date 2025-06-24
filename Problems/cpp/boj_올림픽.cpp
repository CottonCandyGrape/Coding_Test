//https://www.acmicpc.net/problem/8979
//Implementation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
    if(a[1] == b[1]){
        if(a[2] == b[2]){
            if(a[3] == b[3])
                return a[0] < b[0];
            return a[3] > b[3];
        }
        return a[2] > b[2];
    }
    return a[1] > b[1];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> medals;
    for(int i=0; i<n; i++){
        vector<int> tmp(5);
        for(int j=0; j<4; j++) cin >> tmp[j];
        medals.push_back(tmp);
    }

    sort(medals.begin(), medals.end(), cmp);

    medals[0][4] = 1;
    for(int i=1; i<n; i++){
        if(medals[i][1] == medals[i-1][1] && 
            medals[i][2] == medals[i-1][2] && 
            medals[i][3] == medals[i-1][3])
            medals[i][4] = medals[i-1][4];
        else{
            medals[i][4] = i+1;
        }
    }

    for(int i=0; i<n; i++){
        if(medals[i][0]==k)
            cout << medals[i][4];
    }
}