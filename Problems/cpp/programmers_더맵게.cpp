//https://school.programmers.co.kr/learn/courses/30/lessons/42626
//Heap, Greedy?

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    for (const int s : scoville)
        pq.push(-s);
    
    while (-pq.top()<K){
        answer++;
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        pq.push(-(a+2*b));
        if (pq.size()<2) break;
    }
    if (-pq.top()<K) answer=-1;
    
    return answer;
}