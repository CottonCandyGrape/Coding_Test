//https://school.programmers.co.kr/learn/courses/30/lessons/42883#
//Greedy

#include <iostream>
#include <string>
#include <queue>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.size()-k;

    while (k>0 && number.size()>0){
        answer += number.front();
        number.erase(number.begin());
        while(k>0 && answer.size()>0 && answer.back()<number.front()){
            answer.erase(answer.end()-1);
            k--;
        }
    }
    
    answer += number;
    
    if (answer.size()>=size)
        answer.erase(answer.begin() + size, answer.end());
    
    return answer;
}