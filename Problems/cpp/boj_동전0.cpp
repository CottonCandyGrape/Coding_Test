//https://www.acmicpc.net/problem/11047
//Greedy

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k, result=0;
    cin >> n >> k;
    vector<int> vec(n);
    
    for (int i=n-1; i>-1; i--)
        cin >> vec[i];

    for (int i=0; i<n; i++){
        if (k>=vec[i]){
            result += k/vec[i];
            k %= vec[i];
        }
    }

    cout << result;
}