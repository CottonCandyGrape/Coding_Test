//https://www.acmicpc.net/problem/1932
//https://school.programmers.co.kr/learn/courses/30/lessons/43105
//DP

//거꾸로부터 올라가는 것. 정답에 최댓값 안찾아도 돼서 편함.
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> tri) {
    int answer;
    for (int i=tri.size()-1; i>0; i--){
        for (int j=0; j<tri[i].size()-1; j++){
            if (tri[i][j] > tri[i][j+1])
                tri[i-1][j] += tri[i][j];
            else
                tri[i-1][j] += tri[i][j+1];
        }
    }
    
    answer = tri[0][0];
    
    return answer;
}

//첫 번째 풀이
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> tri;
    for (int i=0; i<n; i++){
        vector<int> tmp(i+1);
        for (int j=0; j<i+1; j++)
            cin >> tmp[j];

        tri.push_back(tmp);
    }

    for (int i=1; i<n; i++){
        for (int j=0; j<tri[i].size(); j++){
            if (j==0)
                tri[i][j] += tri[i-1][j];
            else if (j==tri[i].size()-1)
                tri[i][j] += tri[i-1][j-1];
            else
                tri[i][j] += max(tri[i-1][j-1], tri[i-1][j]);
        }
    }

    cout << *max_element(tri[n-1].begin(), tri[n-1].end());
}