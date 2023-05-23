//https://school.programmers.co.kr/learn/courses/30/lessons/150370
//Implementation

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

int days(const string& str){
    int result = 0;
    vector<int> d;

    stringstream ss(str);
    string tmp;
    while (getline(ss, tmp, '.'))
        d.push_back(stoi(tmp));

    result += d[0]*12*28 + d[1]*28 + d[2];

    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char,int> tmap;
    int tdays = days(today); //date를 day로 바꿈
    
    for (int i=0; i<terms.size(); i++) //약관별 기간 int로 저장
        tmap[terms[i].front()] = stoi(terms[i].substr(2));

    for(int i=0; i<privacies.size(); i++){ //현재 개인정보를 day로 바꿔서 비교
        int d = days(privacies[i].substr(0, privacies[i].size()-2));
        int t = tmap[privacies[i].back()];
        d += t*28;

        if (tdays>=d) 
            answer.push_back(i+1);
    }

    return answer;
}