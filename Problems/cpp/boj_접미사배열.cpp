//https://www.acmicpc.net/problem/11656
//Sort

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string pre;
    cin >> pre;

    vector<string> pvec;
    for (int i=0; i<pre.size(); i++)
        pvec.push_back(pre.substr(i));

    sort(pvec.begin(), pvec.end());

    for (const string p : pvec)
        cout << p << '\n';
}