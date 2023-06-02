//https://school.programmers.co.kr/learn/courses/30/lessons/42885
//Greedy

#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    
    for (int i=people.size()-1, j=0; j<=i; i--){
        if (people[i]+people[j]<=limit){
            j++;
        }
        answer++;
    }
    
    return answer;
}