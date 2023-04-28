//https://www.acmicpc.net/problem/1748
//Implementation

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int result = 0;
    int cnt;
    int n;
    cin >> n;
    cnt = to_string(n).size();

    for (int i=0; i<cnt-1; i++){
        result += 9*pow(10, i)*(i+1);
    }
    
    result += (n - pow(10, cnt-1)+1)*cnt;
    cout << result;
}
