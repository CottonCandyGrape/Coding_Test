//https://www.acmicpc.net/problem/15650
//DFS, Back Tracking

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<bool> visit;
vector<int> ans;

void dfs(int depth, int start)
{
    if(depth == m){
        for (const int a : ans)
            cout << a << ' ';
        cout << '\n';
        return;
    }

    for (int i=start; i<n; i++){
        ans[depth] = i+1;
        dfs(depth+1, i+1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    visit.resize(n, false);
    ans.resize(m);

    dfs(0, 0);
}