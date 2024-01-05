//https://www.acmicpc.net/problem/15656
//DFS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
vector<int> ans;
int n, m;

void dfs(int depth, int start)
{
	if(depth == m)
	{
		for(const int a : ans)
			cout << a << ' ';
		cout << '\n';
		return;
	}

	for (int i=start; i<n; i++){
			ans[depth] = vec[i];
			dfs(depth+1, i);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	vec.resize(n);
	ans.resize(m);

	for(int i=0; i<n; i++)
		cin >> vec[i];

	sort(vec.begin(), vec.end());

	dfs(0, 0);
}