//https://school.programmers.co.kr/learn/courses/30/lessons/42586
//Implementation

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    deque<int> pq(progresses.begin(), progresses.end());
    deque<int> sq(speeds.begin(), speeds.end());
    
    while (!pq.empty()){
        for (int i=0; i<sq.size(); i++){
            if (pq[i]<100){
                pq[i] += sq[i];
            }
        }
        
        int cnt=0;
        //while (pq.front()>=100) 이렇게 쓸 경우 pq가 비어도 pq.front()값이 나옴 
        //근데 그것을 100과 비교해서 Error(seg fault)
        //추가로 이 while문 실행 중 pq가 비었을 경우가 생기는데 이 경우 위에 언급한 에러가 생김.
        while (!pq.empty() && pq.front()>=100){
            pq.pop_front();
            sq.pop_front();
            cnt++;
        }

        if (cnt)
            answer.push_back(cnt);
    }
    
    return answer;
}


//다른 풀이
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    
    for (int i=0; i<progresses.size(); i++){
        if ((100-progresses[i])%speeds[i])
            days.push_back((100-progresses[i])/speeds[i] + 1);
        else
            days.push_back((100-progresses[i])/speeds[i]);
    }
    days.push_back(100); //마지막 요소까지 다음 for문에서 고려하기 위해 최대값(100) 추가함
    
    int cnt=0; 
    int day = days[0];
    for (int i=1; i<days.size(); i++){
        cnt++;
        if (day<days[i]){
            answer.push_back(cnt);
            cnt=0;
            day = days[i];
        }
    }
    
    return answer;
}