//https://www.acmicpc.net/problem/3273
//Sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, x, result=0;
    cin >> n;
    
    vector<int> vec(n);
    for (int i=0; i<n; i++)
        cin >> vec[i];
    
    cin >> x;

    sort(vec.begin(), vec.end());

    int s, e, m, v;
    for (int i=0; i<n; i++){
        s = i+1;
        e = n-1;
        v = x - vec[i];
        while (s<=e){
            m = (s+e)/2;
            if (vec[m]==v){
                result++;
                break;
            }
            else if (vec[m]<v)
                s = m+1;
            else if (vec[m]>v)
                e = m-1;
        }
    }
    
    cout << result;
}