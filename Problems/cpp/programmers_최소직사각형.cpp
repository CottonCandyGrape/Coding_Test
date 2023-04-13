//https://school.programmers.co.kr/learn/courses/30/lessons/86491?language=cpp
//Sort

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    for (vector<int>& s : sizes){
        if (s[0]<s[1]) swap(s[0], s[1]);
    }
    
    int v = 0, h = 0;
    for (int i=0; i<sizes.size(); i++){
        v = max(sizes[i][0], v);
        h = max(sizes[i][1], h);
    }
    
    answer = v*h;
    return answer;
}