//https://school.programmers.co.kr/learn/courses/30/lessons/77484
//Implementation

#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero=0, count=0;
    
    unordered_map<int, bool> umap;
    for (const int w : win_nums)
        umap[w] = true;
    
    for (const int l : lottos){
        if (umap[l]) count++;
        else if (!l) zero++;
    }
    
    int minv = min(7-count, 6);
    int maxv = min(7-(count+zero), 6);
    answer = {maxv, minv};
    
    return answer;
}