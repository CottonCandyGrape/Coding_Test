//https://school.programmers.co.kr/learn/courses/30/lessons/17684
//Implementation

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> dict;
int idx=1;

vector<int> solution(string msg) {
    vector<int> answer;
    
    for (; idx<27; idx++)
        dict[string(1, (char)(idx+64))] = idx;
    
    string tmp = "";
    for (int i=0; i<msg.size(); i++){
        tmp += msg[i];
        if (!dict[tmp]){
            string key = tmp.substr(0, tmp.size()-1);
            answer.push_back(dict[key]);
            dict[tmp] = idx;
            idx++; i--;
            tmp = "";
        }
    }
    
    answer.push_back(dict[tmp]); //i--를 하니깐 tmp는 무조건 공백이 아님
    
    return answer;
}