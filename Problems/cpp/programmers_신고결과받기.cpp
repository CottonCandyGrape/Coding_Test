//https://school.programmers.co.kr/learn/courses/30/lessons/92334
//Implementation

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//다른 사람 풀이. 3.부분이 깔끔하다
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // 1.
    const int n = id_list.size();
    map<string, int> Conv;
    for (int i = 0; i < n; i++) Conv[id_list[i]] = i;

    // 2.
    vector<pair<int, int>> v;
    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());
    for (const auto& s : report) {
        stringstream in(s);
        string a, b; in >> a >> b;
        v.push_back({ Conv[a], Conv[b] });
    }

    // 3.
    vector<int> cnt(n), ret(n);
    for (const auto& [a, b] : v) cnt[b]++;
    for (const auto& [a, b] : v) if (cnt[b] >= k) ret[a]++;
    return ret;
}

//내 풀이
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    unordered_set<string> stmp(report.begin(), report.end());
    report = vector<string>(stmp.begin(), stmp.end());
   
    unordered_map<string, vector<string>> umap;
    for (const auto& r : report){
        auto it = r.find(' ');
        string a = string(r.begin(), r.begin()+it); //신고한 사람.
        string b = string(r.begin()+it+1, r.end()); //신고 당한사람.
        umap[b].push_back(a); //vecotr의 개수로 몇번 당했는지 알 수 있음.
    }
    
    for (int i=0; i<id_list.size(); i++){
        string tmp = id_list[i];
        if (umap[tmp].size()>=k){ //k번이 넘으면
            for (int j=0; j<umap[tmp].size(); j++){
                string ctmp = umap[tmp][j]; //그 벡터 안에 있는 사람들이 신고한 사람이므로 
                //그 사람의 idx 찾아서 +1 해준다.
                int idx = find(id_list.begin(), id_list.end(), ctmp) - id_list.begin();
                answer[idx]++;
            }
        }
    }
    
    return answer;
}