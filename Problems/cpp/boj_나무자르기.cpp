//https://www.acmicpc.net/problem/2805
//Binary Search

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, h;
    long long s=0, e=2e9;
    cin >> n >> m;

    vector<int> vec(n);
    for (int i=0; i<n; i++)
        cin >> vec[i];
    
    while (s<=e){
        long long mid = (s+e)/2;
        long long len = 0;

        for (const int v : vec){
            if (v>mid)
                len += v-mid;
        }

        if (len>=m){
            s = mid+1;
            h = mid;
        }
        else{
            e = mid-1;
        }
    }

    cout << h;
}