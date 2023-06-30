//https://school.programmers.co.kr/learn/courses/30/lessons/92341
//Implementation

#include <string>
#include <vector>
#include <map>
#include <cmath>
#define OUT 1439

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, vector<int>> vmap;
    
    for (const auto& r : records){
        int time = stoi(r.substr(0,2))*60 + stoi(r.substr(3,2));
        int car = stoi(r.substr(6,4));
        vmap[car].push_back(time);
    }
    
    for (auto it=vmap.begin(); it!=vmap.end(); it++){
        if (it->second.size()%2 != 0) it->second.push_back(OUT);
    }
    
    for (auto it=vmap.begin(); it!=vmap.end(); it++){
        vector<int> tmp = it->second;
        int times = 0;
        for (int i=0; i<tmp.size(); i+=2){
            times += tmp[i+1]-tmp[i];
        }
        times -= fees[0];
        
        if (times<0){
            answer.push_back(fees[1]);
        }
        else{
            int extra = ceil(times / (double)fees[2]);
            int fee = fees[1] + extra*fees[3];
            answer.push_back(fee);
        }
    }
    
    return answer;
}