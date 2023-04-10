//https://www.acmicpc.net/problem/1072
//Binary Search

#include <iostream>

using namespace std;

long x, y; //c++는 자료형에 주의! long도 4byte인데 왜 되지? -> 채점 서버가 리눅스인듯?
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> y;

    int z = 100*y / x;
    int s=1; int e=1e9;

    int result=0;
    while (s<=e){
        int mid = (s+e)/2;

        int newz = 100*(y+mid) / (x+mid);
        if (newz>z){
            e = mid-1;
            result = mid;
        }
        else
            s = mid+1;
    }
    if (!result) cout << -1;
    else cout << result;
}