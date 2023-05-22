//https://www.acmicpc.net/problem/14888
//Brute-force, DFS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> op(4);
vector<int> vec;
int n, minv=1e9, maxv=-1e9;

void dfs(int depth, int num, int a, int s, int m, int d){
    if (depth==n){
        minv = min(minv, num);
        maxv = max(maxv, num);
        return;
    }

    if (a)
        dfs(depth+1, num+vec[depth], a-1, s, m, d);
    
    if (s)
        dfs(depth+1, num-vec[depth], a, s-1, m, d);
    
    if (m)
        dfs(depth+1, num*vec[depth], a, s, m-1, d);
    
    if (d)
        dfs(depth+1, num/vec[depth], a, s, m, d-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vec = vector<int>(n);
    for (int i=0; i<n; i++)
        cin >> vec[i];

    for (int i=0; i<4; i++)
        cin >> op[i];

    dfs(1, vec[0], op[0], op[1], op[2], op[3]);
    
    cout << maxv << '\n';
    cout << minv << '\n';
}