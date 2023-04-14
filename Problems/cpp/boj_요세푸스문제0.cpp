//https://www.acmicpc.net/problem/11866
//Implementation


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> result;
    deque<int> dq;
    for (int i=1; i<=n; i++)
        dq.push_back(i);
    
    while (!dq.empty()){
        for (int i=0; i<k-1; i++){
            dq.push_back(dq.front());
            dq.pop_front();
        }
        result.push_back(dq.front());
        dq.pop_front();
    }
    
    cout << '<';
    for (int i=0; i<n; i++){
        if (i!=n-1){
            cout << result[i] << ", ";
        }
        else{
            cout << result[i] << '>';
        }
    }
}