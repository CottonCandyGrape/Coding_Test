//https://school.programmers.co.kr/learn/courses/30/lessons/12939?language=cpp
//Implementation

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    string token = "";
    vector<int> vec;
    stringstream ss(s);
    while (getline(ss, token, ' ')){
        vec.push_back(stoi(token));
    }
    
    sort(vec.begin(), vec.end());
    answer = to_string(vec.front()) + ' ' + to_string(vec.back());
    
    return answer;
}