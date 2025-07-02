//https://www.acmicpc.net/problem/20920
//Implementation

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, string>& p1, const pair<int, string>& p2){
	if(p1.first == p2.first){
		if(p1.second.size() == p2.second.size()){
			return p1.second < p2.second;
		}
		else
			return p1.second.size() > p2.second.size();
	}
	else
		return p1.first > p2.first;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); 
	vector<pair<int, string>> vec;
	int n, m;
	cin >> n >> m;
	map<string, int> strMap;
	string str;
	for(int i=0; i<n; i++){
		cin >> str;
		if(str.size()<m) continue;
		strMap[str]++;
	}

	for(const auto& [k, v] : strMap)
		vec.push_back(make_pair(v, k));

	sort(vec.begin(), vec.end(), cmp);

	for(int i=0; i<vec.size(); i++){
		cout << vec[i].second << '\n';
	}
}