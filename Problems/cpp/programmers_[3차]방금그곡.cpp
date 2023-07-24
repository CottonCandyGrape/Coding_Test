//https://school.programmers.co.kr/learn/courses/30/lessons/17683
//Implementation, Sort

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int playTime(string s, string e){
    int sh, sm, eh, em;
    sh = stoi(s.substr(0, 2));
    sm = stoi(s.substr(3, 2));
    eh = stoi(e.substr(0, 2));
    em = stoi(e.substr(3, 2));
    
    return eh*60 + em - (sh*60 + sm);
}

vector<string> split(string str){
    vector<string> result;
    
    stringstream ss(str);
    string tmp;
    while (getline(ss, tmp, ','))
        result.push_back(tmp);
    
    return result;
}

vector<string> scoreVec(string str){
    vector<string> result;
    
    for (int i=0; i<str.size(); i++){
        if (str[i] == '#')
            //*(result.end()-1) += '#';
            result.back() += '#';
        else
            result.push_back(string(1, str[i]));
    }
    
    return result;
}

bool cmp (const pair<string, int> a, const pair<string, int> b){
    return a.second > b.second;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    vector<pair<string, int>> aVec;
    
    for (const string music : musicinfos){
        vector<string> info = split(music); // 문자열 ,로 파싱하여 정보 구분
        
        int time = playTime(info[0], info[1]); //재생 시간
        string title = info[2]; //제목
        vector<string> mVec = scoreVec(m); // #을 구분하여 string 악보를 vector로 파싱. 
        vector<string> sVec = scoreVec(info[3]);
        
        int cnt = time / sVec.size();
        int rcnt = time % sVec.size();
        vector<string> pVec; //재생된 악보
        for (int i=0; i<cnt; i++){
            pVec.insert(pVec.end(), sVec.begin(), sVec.end());
        }
        
        pVec.insert(pVec.end(), sVec.begin(), sVec.begin()+rcnt);
        
        if (mVec.size()>pVec.size()) continue; // 재생시간보다 악보가 짧다면 볼필요 X.
        
        for (int i=0; i<pVec.size(); i++){
            if (pVec[i] == mVec[0]){ // 같은 부분이 시작되면
                bool flag = true;
                for (int j=0; j<mVec.size(); j++){ // 기억한 멜로디가 다 맞는지 확인
                    if (pVec[i+j]!=mVec[j]){
                        flag = false; 
                        break;
                    } 
                }
                
                if (flag){ // 다 맞으면 제목과 재생시간을 정답 후보에 넣기
                    aVec.push_back(make_pair(title, time)); 
                    break;
                } 
            }
        }
        
    }

    if (!aVec.empty()) { //정답 후보가 있으면
        stable_sort(aVec.begin(), aVec.end(), cmp); // 순서 바뀌지 않게 stable_sort 해주고
        answer = aVec[0].first; //정답 입력
    }
    // 정답 후보 없으면 "(None)" 출력
    
    return answer;
}