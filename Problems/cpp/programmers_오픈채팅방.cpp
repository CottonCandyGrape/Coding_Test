//https://school.programmers.co.kr/learn/courses/30/lessons/42888
//Implementation

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

////두번째 풀이

vector<string> split(string str)
{
    vector<string> result;
    stringstream ss(str);
    string tmp = "";
    while(getline(ss, tmp, ' '))
        result.push_back(tmp);
    
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> umap;
    vector<vector<string>> splited;
    
    for (const string& str : record)
        splited.push_back(split(str));
    
    for (const auto& svec : splited)
    {
        if (svec[0] != "Leave")
            umap[svec[1]] = svec[2];
    }
    
    for (const auto& svec : splited)
    {
        if (svec[0] == "Enter")
             answer.push_back(umap[svec[1]] + "님이 들어왔습니다.");
        else if (svec[0] == "Leave")
             answer.push_back(umap[svec[1]] + "님이 나갔습니다.");
    }
    
    return answer;
}

////첫번째 풀이

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