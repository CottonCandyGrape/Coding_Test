//https://school.programmers.co.kr/learn/courses/30/lessons/43238
//Binary Search

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long end = *max_element(times.begin(), times.end()) * (long long)n;
    //int*int에서 overflow 발생할 수 있음. 
    //발생 후의 값이 end(long long)으로 들어가기 때문에 
    //미리 형변환 해준다.
    long long start = 1;
    
    while (start <= end){
        long long mid = (start+end)/2;
        
        long long tmp = 0;
        for (const auto& t : times)
            tmp += mid/t;
        
        if (tmp>=n){
            end = mid-1;
            answer = mid;
        }
        else
            start = mid+1;
    }
    
    return answer;
}