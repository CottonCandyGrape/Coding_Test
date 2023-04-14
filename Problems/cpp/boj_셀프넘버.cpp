//https://www.acmicpc.net/problem/4673
//Implementation

#include <iostream>
#include <string>
#include <vector>
#define MAX 10001

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<bool> self(MAX, false);

    for (int i=1; i<MAX; i++){
        int tmp = i, num = i;
        while (tmp){
            num += tmp%10;
            tmp /= 10;
        }
        
        if (num<MAX) self[num] = true;
    }
    for (int i=1; i<MAX; i++){
        if (!self[i]) cout << i << '\n';
    }
}