//https://www.acmicpc.net/problem/18353
//DP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> vec(n);
    vector<int> lis(n, 1);

    for (int i=0; i<n; i++)
        cin >> vec[i];
    reverse(vec.begin(), vec.end());

    for (int i=1; i<n; i++){
        for (int j=0; j<i; j++){
            if (vec[j]<vec[i]){
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }

    int val = lis[0];
    int cnt = 0;
    for (int i=1; i<n; i++){
        if (val<lis[i])
            val = lis[i];
        else
            cnt++;
    }
    
    cout << cnt;
}