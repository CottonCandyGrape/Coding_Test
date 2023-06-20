//https://www.acmicpc.net/problem/1946
//Greedy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for (int ti=0; ti<t; ti++){
        int n;
        cin >> n;

        vector<pair<int, int>> vec(n);
        int a, b;
        for (int i=0; i<n; i++){
            cin >> a >> b; 
            vec[i] = make_pair(a, b);
        }

        sort(vec.begin(), vec.end());

        int val = vec[0].second;
        int result = 1;
        for (int i=1; i<n; i++){
            if (vec[i].second < val){
                val = vec[i].second;
                result++;
            }
        }
        
        cout << result << '\n';
    }
}