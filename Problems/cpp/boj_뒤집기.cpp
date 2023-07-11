//https://www.acmicpc.net/problem/1439
//Greedy

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//예전이 더 잘 풀어놨네.
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int cnt = 0;
    for (int i=1; i<str.size(); i++){
        if (str[i-1]!=str[i]) cnt++;
    }

    cout << (cnt+1)/2;
}

//23.07.07 풀이
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str, rstr;
    cin >> str;

    rstr += str[0];
    for (int i=1; i<str.size(); i++){
        if (str[i-1]!=str[i]){
            rstr += str[i];
        }
    }

    int a = count(rstr.begin(), rstr.end(), '1');
    int b = rstr.size() - a;

    cout << min(a, b);
}