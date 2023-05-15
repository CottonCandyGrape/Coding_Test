//https://www.acmicpc.net/problem/11399
//Greedy, Sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, tmp=0, result=0;
    cin >> n;
    
    vector<int> vec(n);
    for (int i=0; i<n; i++)
        cin >> vec[i];
    
    sort(vec.begin(), vec.end());
    for (const int& v : vec){
        tmp += v;
        result += tmp;
    }
    
    cout << result;
}