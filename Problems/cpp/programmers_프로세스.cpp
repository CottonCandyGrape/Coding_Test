//https://school.programmers.co.kr/learn/courses/30/lessons/42587
//Implementation

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int maxv = *max_element(priorities.begin(), priorities.end()); 
    deque<int> q(priorities.begin(), priorities.end());
    
    while (true){
        int now = q.front();
        q.pop_front();

        if (now < maxv){
            q.push_back(now);
        }
        else{
            answer++;
            if (location==0) 
                return answer;
            else
                maxv = *max_element(q.begin(), q.end()); 
        }

        location = (location+q.size()-1)%q.size();
    }
}