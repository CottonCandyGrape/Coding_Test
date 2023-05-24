//https://school.programmers.co.kr/learn/courses/30/lessons/42842
//완전 탐색

#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i=1; i<yellow+1; i++){
        if (yellow%i != 0) continue;
        else{
            int w = yellow/i;
            int h = i;
            int tmp = 2*(w+2) + 2*h;
            if (tmp == brown){
                answer = {w+2, h+2};
                break;
            }
        }
    }
    
    return answer;
}