//https://www.acmicpc.net/problem/2110
//Binary Search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> c;
    
    vec.resize(n);
    for (int i=0; i<n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());

    int s = 1;
    int e = vec[n-1]-vec[0];

    int result = 0;
    while (s<=e){
        int mid = (s+e)/2;
        int count = 1; //처음부터 한개
        int val = vec[0];

        for (int i=1; i<n; i++){
            if (vec[i]>=mid+val){
                count++;
                val = vec[i];
            }
        }

        if (count >= c){
            s = mid + 1;
            result = mid;
        }
        else
            e = mid - 1;
    }

    cout << result;
}