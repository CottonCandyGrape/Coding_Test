//https://www.acmicpc.net/problem/1026
//Greedy, Sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, result=0;
    cin >> n;

    vector<int> avec(n);
    vector<int> bvec(n);

    for (int i=0; i<n; i++)
        cin >> avec[i];

    for (int i=0; i<n; i++)
        cin >> bvec[i];

    sort(avec.begin(), avec.end());
    sort(bvec.rbegin(), bvec.rend());

    for (int i=0; i<n; i++)
        result += avec[i]*bvec[i];

    cout << result;
}