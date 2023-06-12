//https://school.programmers.co.kr/learn/courses/30/lessons/42889
//Implementation, Sort

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<pair<double, int>> fail;
    vector<int> current(N+1, 0);
    int players = stages.size();
    
    for (const int s : stages)
        current[s]++;
    
    for (int i=1; i<N+1; i++){
        if (players){
            fail.push_back(make_pair(-(double)current[i]/players, i));
            players -= current[i];
        }
        else
            fail.push_back(make_pair(0, i));
    }
    
    sort(fail.begin(), fail.end());
    for (const auto& f : fail)
        answer.push_back(f.second);
    
    return answer;
}