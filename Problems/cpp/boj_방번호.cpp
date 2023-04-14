//https://www.acmicpc.net/problem/1475
//Implementation

#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<char, int>& a, const pair<char, int>& b){
    if (a.second < b.second) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    cin >> str;

    map<char, int> smap;
    for (const auto& s : str){
        if (s=='6')
            smap['9']++;
        else
            smap[s]++;
    }

    auto max = max_element(smap.begin(), smap.end(), cmp);
    if (max->first=='9'){
        max->second = max->second%2==0 ? max->second/2 : max->second/2 + 1;
    }
    
    max = max_element(smap.begin(), smap.end(), cmp);
    cout << max->second;
}