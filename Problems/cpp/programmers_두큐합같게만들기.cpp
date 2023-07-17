//https://school.programmers.co.kr/learn/courses/30/lessons/118667
//Implementation, queue

#include <string>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    deque<int> q1(queue1.begin(), queue1.end());
    deque<int> q2(queue2.begin(), queue2.end());
    
    long long l = accumulate(q1.begin(), q1.end(), 0LL); 
    long long r = accumulate(q2.begin(), q2.end(), 0LL); 
    long long sum = (l+r)/2 ; 
    
    for (int i=0; i<queue1.size()*3; i++){
        if (l==sum) return answer;
        
        if (l<sum){
            l += q2.front();
            r -= q2.front();
            q1.push_back(q2.front());
            q2.pop_front();
        }
        else if (l>sum){
            l -= q1.front();
            r += q1.front();
            q2.push_back(q1.front());
            q1.pop_front();
        }
        
        answer++;
    }
    
    return -1;
}