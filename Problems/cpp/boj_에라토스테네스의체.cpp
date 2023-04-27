//https://www.acmicpc.net/problem/2960
//Implementation

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<bool> era(n+1, false);

    for (int i=2; i<n+1; i++){
        for (int j=i; j<n+1; j=j+i){
            if (!era[j]) {
                era[j] = true;
                k--;

                if (k==0){
                    cout << j; 
                    break; 
                } 
            }
        }
    }
}