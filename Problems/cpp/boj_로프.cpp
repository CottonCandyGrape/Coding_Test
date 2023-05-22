//https://www.acmicpc.net/problem/2217
//Greedy, Sort

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> r;
    int n, tmp, w=0;
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> tmp;
        r.push_back(tmp);
    }

    sort(r.rbegin(), r.rend());

    for (int i=0; i<n; i++){
        int weight = (i+1) * r[i];
        if (w<weight)
            w = weight;
    }
    
    cout << w;
}