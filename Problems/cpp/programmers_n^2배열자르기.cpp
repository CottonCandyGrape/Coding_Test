//https://school.programmers.co.kr/learn/courses/30/lessons/87390
//Implementation

#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (long long i=left; i<right+1; i++){
        int r = i/n;
        int c = i%n;
        answer.push_back(max(r, c)+1);
    }
    
    return answer;
}