//https://school.programmers.co.kr/learn/courses/30/lessons/118667
//Implementation, queue

#include <string>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long left = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long right = accumulate(queue2.begin(), queue2.end(), 0LL);
    deque<int> dq1 = deque(queue1.begin(), queue1.end());
    deque<int> dq2 = deque(queue2.begin(), queue2.end());
    
    for (int i=0; i<queue1.size()*3; i++)
    {
        if (left==right) return answer;
        
        if (left>right)
        {
            left -= dq1.front();
            right += dq1.front();
            dq2.push_back(dq1.front());
            dq1.pop_front();
        }
        else if (left<right)
        {
            left += dq2.front();
            right -= dq2.front();
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }
        
        answer++;
    }
    
    return -1;
}