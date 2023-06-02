//https://school.programmers.co.kr/learn/courses/30/lessons/42578
//Hash

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer=1;
    unordered_map<string, int> cmap;
    
    for (int i=0; i<clothes.size(); i++)
        cmap[clothes[i][1]]++;
    
    for (const auto& c : cmap)
        answer *= c.second+1;
    
    return answer-1;
}