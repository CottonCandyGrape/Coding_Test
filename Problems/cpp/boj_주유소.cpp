//https://www.acmicpc.net/problem/13305
//Greedy

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<long long> road(n-1);
    vector<long long> city(n);

    for (int i=0; i<n-1; i++)
        cin >> road[i];

    for (int i=0; i<n; i++)
        cin >> city[i];

    long long total = 0;
    long long cheap = city[0];
    for (int i=0; i<n-1; i++){
        if (city[i]<cheap)
            cheap = city[i];
        total += cheap*road[i];
    }

    cout << total;
}