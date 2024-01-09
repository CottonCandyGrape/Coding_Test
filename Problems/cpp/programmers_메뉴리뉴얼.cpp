//https://school.programmers.co.kr/learn/courses/30/lessons/72411
//DFS, 조합

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> omap;

void comb(int start, int cnt, string key, string& word)
{
    if(cnt == key.size())
    {
        omap[key]++;
        return;
    }
    
    for (int i=start; i<word.size(); i++)
        comb(i+1, cnt, key+word[i], word);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (string order : orders)
    {
        sort(order.begin(), order.end()); //order 정렬
        for (const int c : course) //메뉴 개수로 나눠서
        {
            if (c <= order.size()) 
                comb(0, c, "", order); //조합하기
            else 
                break;
        }
    }
    
    vector<vector<pair<int, string>>> cVec;
    for (const int c : course)
    {
        vector<pair<int, string>> tVec;
        for(const auto& [k, v] : omap)
        {
            if(k.size() == c && v>=2) //메뉴 개수가 같고 2인이상 주문한 조합만 고르기
                tVec.push_back(make_pair(v, k));
        }
        cVec.push_back(tVec);
    }
    
    for(auto& vec : cVec)
    {
        sort(vec.rbegin(), vec.rend()); //가장 많이 주문된 순으로 정렬
        int max = vec[0].first; //첫번째가 가장 많이 주문된 횟수
        for(const auto& v : vec)
        {
            if(max == v.first) //가장 많이 주문된 횟수와 같은 메뉴들을 모두 추가
                answer.push_back(v.second);
        }
    }
    
    sort(answer.begin(), answer.end()); //최종 메뉴 정렬
    
    return answer;
}