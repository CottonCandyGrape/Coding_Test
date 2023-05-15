//https://www.acmicpc.net/problem/18353
//DP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;

    vector<int> vec(n);
    vector<int> dp(n, 1);
    for (int i=0; i<n; i++)
        cin >> vec[i];

    reverse(vec.begin(), vec.end());
    
    for (int i=1; i<n; i++){
        for (int j=0; j<i; j++){
            if (vec[j] < vec[i])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    
    m = *max_element(dp.begin(), dp.end());
    cout << n-m;
}