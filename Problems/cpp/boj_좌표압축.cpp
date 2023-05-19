//https://www.acmicpc.net/problem/18870
//Sort, unordered_set, unordered_map

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    vector<int> vec;
    vector<int> tvec;
    unordered_set<int> s;
    unordered_map<int, int> m;

    cin >> n;
    int tmp;
    for (int i=0; i<n; i++){
        cin >> tmp;
        vec.push_back(tmp);
    }
    
    s = unordered_set<int>(vec.begin(), vec.end());
    tvec = vector<int>(s.begin(), s.end());
    sort(tvec.begin(), tvec.end());

    for (int i=0; i<tvec.size(); i++)
        m[tvec[i]] = i;
    
    for (const int v : vec)
        cout << m[v] << ' ';
}