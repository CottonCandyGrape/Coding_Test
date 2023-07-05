//https://school.programmers.co.kr/learn/courses/30/lessons/42888
//Implementation

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<string, string> umap;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    vector<vector<string>> splited(record.size());
    for (int i=0; i<record.size(); i++){
        stringstream ss(record[i]);
        string tmp;
        while (ss >> tmp){
            splited[i].push_back(tmp);
        }
    }
    
    for (const auto& s : splited){
        if (s[0] != "Leave"){
            umap[s[1]] = s[2];
        }
    }
    
    for (const auto s : splited){
        if (s[0]=="Enter"){
            answer.push_back(umap[s[1]] + "님이 들어왔습니다.");
        }
        else if (s[0]=="Leave"){
            answer.push_back(umap[s[1]] + "님이 나갔습니다.");
        }
    }
    
    return answer;
}