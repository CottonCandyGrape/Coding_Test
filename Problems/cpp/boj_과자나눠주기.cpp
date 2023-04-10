//https://www.acmicpc.net/problem/16401
//Binary Search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<int> snack;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    snack.resize(n);
    for (int i=0; i<n; i++)
        cin >> snack[i];

    int s = 1;
    int e = *max_element(snack.begin(), snack.end());

    int result = 0;
    while (s<=e){
        int count = 0;
        int mid = (s+e)/2;

        for (const int s : snack)
            if (mid<=s) count += s/mid;

        if (count>=m){
            s = mid + 1;
            result = mid;
        }
        else
            e = mid - 1;
    }

    cout << result;
}