//https://school.programmers.co.kr/learn/courses/30/lessons/42862
//Greedy

#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    
    vector<int> tmp;
    for (const int& l : lost){
        if (find(reserve.begin(), reserve.end(), l) != reserve.end())
            tmp.push_back(l);
    }
    
    for (const int& t : tmp){
        answer++;
        int lidx = find(lost.begin(), lost.end(), t) - lost.begin();
        int ridx = find(reserve.begin(), reserve.end(), t) - reserve.begin();
        if (lidx >= 0)
        	lost.erase(lost.begin() + lidx);
        if (ridx >= 0)
        	reserve.erase(reserve.begin() + ridx);
    }
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for (const int& l : lost){
        for (int i=0; i<reserve.size(); i++){
            if (l-1 == reserve[i] || l+1 == reserve[i]){
                reserve.erase(reserve.begin()+i);
                answer++;
                break;
            }
        }
        
        if (reserve.empty()) break;
    }
    
    return answer;
}