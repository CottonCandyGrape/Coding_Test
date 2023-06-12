//https://school.programmers.co.kr/learn/courses/30/lessons/118666?language=cpp
//Implementation

#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    unordered_map<char, int> umap;
    vector<pair<char, char>> chars = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}};
    
    for (int i=0; i<survey.size(); i++){
        if (choices[i]<4)
            umap[survey[i][0]] += 4-choices[i];
        else if (choices[i]>4)
            umap[survey[i][1]] += choices[i]-4;
    }
    
    for (int i=0; i<chars.size(); i++){
        if (umap[chars[i].first]>=umap[chars[i].second])
            answer += chars[i].first;
        else
            answer += chars[i].second;
    }
    
    return answer;
}