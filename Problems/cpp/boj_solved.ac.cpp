//https://www.acmicpc.net/problem/18110
//Implementation

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, cnt, sum=0;
    vector<int> vec;
    
    cin >> n;
    if(n==0) {
        cout << 0;
        return 0;
    }
    
    vec.resize(n);
    for(int i=0; i<n; i++) cin >> vec[i];

    cnt = round(n*0.15);

    sort(vec.begin(), vec.end());
    for(int i=cnt; i<n-cnt; i++) sum += vec[i];

    cout << round((double)sum/(n-2*cnt));
}