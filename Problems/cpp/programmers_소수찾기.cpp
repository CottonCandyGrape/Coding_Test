//https://school.programmers.co.kr/learn/courses/30/lessons/42839
//완전 탐색

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

bool era(int num){
    if (num<2) return false;

    for (int i=2; i<=sqrt(num); i++) //여기서 i<sqrt(num)+1; 하면 왜 틀리지?
        if (num%i==0) return false;

    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> nset;

    sort(numbers.begin(), numbers.end());

    do{
        string tmp = "";
        for (int i=0; i<numbers.size(); i++){
            tmp += numbers[i];
            nset.insert(stoi(tmp));
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    for (const int n : nset){
        if (era(n)){
            answer++; 
        } 
    }

    return answer;
}