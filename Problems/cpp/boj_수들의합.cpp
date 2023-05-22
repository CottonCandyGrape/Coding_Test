//https://www.acmicpc.net/problem/1789
//Greedy

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long n;
    int result=-1, num=1;
    cin >> n;

    while (n>=0){
        n -= num;
        num++;
        result++;
    }

    cout << result;
}