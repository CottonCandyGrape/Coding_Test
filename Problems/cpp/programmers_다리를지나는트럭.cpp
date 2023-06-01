//https://school.programmers.co.kr/learn/courses/30/lessons/42583
//Implementation

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer=0, tw=0;
    deque<int> bq(bridge_length, 0);
    deque<int> tq(truck_weights.begin(), truck_weights.end());
    
    while (!bq.empty()){
        answer++;
        tw -= bq.front();
        bq.pop_front();
        
        if (!tq.empty()){
            if (tw+tq.front() <= weight){
                tw += tq.front();
                bq.push_back(tq.front());
                tq.pop_front();
            }
            else
                bq.push_back(0);
        }
    }
    
    return answer;
}