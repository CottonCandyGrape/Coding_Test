//https://school.programmers.co.kr/learn/courses/30/lessons/60057?language=cpp
//Implementation

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for (int i=1; i<(s.size()/2)+1; i++){
        vector<string> splited;
        string tmp = "";
        for (int j=0; j<s.size(); j+=i){
            splited.push_back(s.substr(j, i));
        }
        splited.push_back(""); //밑에 for 문에서 실제 마지막 요소까지 정답에 넣어주기 위해
        
        int cnt = 1;
        for (int k=0; k<splited.size()-1; k++){
            if (splited[k]==splited[k+1]){
                cnt++;
            }
            else{
                if (cnt>1){
                    tmp += to_string(cnt);
                }
                tmp += splited[k];
                cnt = 1;
            }
        }
        
        answer = min(answer, (int)tmp.size()); //(int)한 이유 : min() 매개변수 타입 안맞다고 나와서.
    }
    
    return answer;
}