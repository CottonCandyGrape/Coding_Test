//https://www.acmicpc.net/problem/1931
//Greedy, Sort


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, s, e, result=1;
    vector<pair<int, int>> vec;
    cin >> n;

    
    for (int i=0; i<n; i++){
        cin >> s >> e;
        vec.push_back(make_pair(s, e));
    }

    sort(vec.begin(), vec.end(), cmp);

    int start = vec[0].second;
    for (int i=1; i<n; i++){
        if (start <= vec[i].first){
            result++;
            start = vec[i].second;
        }
    }

    cout << result;
}