//https://www.acmicpc.net/problem/1193
//Implementation

#include <iostream>

using namespace std;

int main() {
    int n, x=1;
    cin >> n;

    while(n>x){
        n -= x;
        x++;
    }
    
    if(x%2==0)
        cout << n << '/' << x+1-n;
    else
        cout << x+1-n << '/' << n;
}