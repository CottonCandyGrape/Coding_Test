//https://www.acmicpc.net/problem/2178
//DFS, BFS

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

vector<string> mat;
vector<vector<int>> visit;
int n, m;

int bfs()
{
	deque<pair<int, int>> dq(1, make_pair(0, 0));

	while(!dq.empty()){
		int x = dq.front().first;
		int y = dq.front().second;
		dq.pop_front();

		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx<0 || nx>=n || ny<0 || ny>=m)
				continue;
			if(visit[nx][ny]!=0)
				continue;
			if(mat[nx][ny] == '0')
				continue;
			if(mat[nx][ny] == '1')
			{
				visit[nx][ny] = visit[x][y] + 1;
				dq.push_back(make_pair(nx, ny));
			}
		}
	}
	
	return visit[n-1][m-1];
}

int main() { 
	cin >> n >> m;

	mat.resize(n);
	visit.resize(n, vector<int>(m, 0));
	for(int i=0; i<n; i++){
		cin >> mat[i];
	}

	cout << bfs() + 1 << endl;
}