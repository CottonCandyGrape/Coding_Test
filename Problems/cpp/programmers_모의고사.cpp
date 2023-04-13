//https://school.programmers.co.kr/learn/courses/30/lessons/42840?language=cpp
//Brute force

#include <vector>
#include <algorithm>

using namespace std;

vector<int> spj1 = {1,2,3,4,5};
vector<int> spj2 = {2,1,2,3,2,4,2,5};
vector<int> spj3 = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> spjs(3, 0);
    
    for (int i=0; i<answers.size(); i++){
        if (answers[i]==spj1[i%spj1.size()]) spjs[0]++;
        if (answers[i]==spj2[i%spj2.size()]) spjs[1]++;
        if (answers[i]==spj3[i%spj3.size()]) spjs[2]++;
    }
    
    int max = *max_element(spjs.begin(), spjs.end());
    for (int i=0; i<spjs.size(); i++){
        if (spjs[i]==max) answer.push_back(i+1);
    }
    
    return answer;
}