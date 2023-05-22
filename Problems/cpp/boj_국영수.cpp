//https://www.acmicpc.net/problem/10825
//Sort

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int kor, eng, math; string name;
    vector<tuple<int, int, int, string>> stu;
    tuple<int, int, int, string> tmp;
    
    for (int i=0; i<n; i++){
        cin >> name >> kor >> eng >> math;
        tmp = make_tuple(-kor, eng, -math, name);
        stu.push_back(tmp);
    }

    sort(stu.begin(), stu.end());

    for (const auto& s : stu)
        cout << get<3>(s) << '\n';
}