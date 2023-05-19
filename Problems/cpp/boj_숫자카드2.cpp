//https://www.acmicpc.net/problem/10816
//Sort, Binary Search

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//Binary Search 풀이
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;

    cin >> n;
    vector<int> vec(n);
    for (int i=0; i<n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());
    
    cin >> m;
    int tmp;
    for (int i=0; i<m; i++){
        cin >> tmp;
        cout << upper_bound(vec.begin(), vec.end(), tmp) - lower_bound(vec.begin(), vec.end(), tmp) << ' ';
    }
}

//unordered_map 풀이
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    unordered_map<int, int> a, b;

    cin >> n;
    int tmp;
    for (int i=0; i<n; i++){
        cin >> tmp;
        a[tmp]++;
    }
    
    
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> tmp;
        cout << a[tmp] << ' ';
    }
}