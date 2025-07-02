//https://www.acmicpc.net/problem/1940
//Implementation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, result=0;
	cin >> n >> m;
	
	vector<int> vec(n);
	for(int i=0; i<n; i++) cin >> vec[i];

	sort(vec.begin(), vec.end());
	for(int i=n-1; i>-1; i--){
		if(vec[i]>m) vec.pop_back();
		else break;
	}

	int l=0, r=vec.size()-1;
	while(l<r){
		int num = vec[l]+vec[r];
		if(num<m){
			l++;
		}
		else if(num>m){
			r--;
		}
		else if(num==m){
			result++;
			l++; r--;
		}
	}

	cout << result;
}