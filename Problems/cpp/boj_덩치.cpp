//https://www.acmicpc.net/problem/7568
//Implementation

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> result(n, 1);
    vector<pair<int, int>> vec(n);
    int a, b;
    for (int i=0; i<n; i++){
        cin >> a >> b;
        vec[i] = make_pair(a, b);
    }

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i==j) continue;
            if (vec[i].first < vec[j].first && vec[i].second < vec[j].second){
                result[i]++;
            }
        }
    }

    for(const int& r : result)
        cout << r << ' ';
}