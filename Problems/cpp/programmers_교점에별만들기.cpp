//https://school.programmers.co.kr/learn/courses/30/lessons/87377
//Implementation

#include <bits/stdc++.h>


using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    int n = line.size();
    set<pair<long long, long long>> coords;
    
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            long long ad_bc = (long long)line[i][0]*line[j][1] - (long long)line[i][1]*line[j][0];
            if (ad_bc != 0){
                long long bf_ed = (long long)line[i][1]*line[j][2] - (long long)line[i][2]*line[j][1];
                long long ec_af = (long long)line[i][2]*line[j][0] - (long long)line[i][0]*line[j][2];
                if ((bf_ed%ad_bc)==0 && (ec_af%ad_bc)==0)
                    coords.insert(make_pair(ec_af/ad_bc, bf_ed/ad_bc));
            }
        }
    }
    
    long long minx=1e10, maxx=-1e10, miny=1e10, maxy=-1e10;
    for (const auto& c : coords){
        minx = min(minx, c.second);
        maxx = max(maxx, c.second);
        miny = min(miny, c.first);
        maxy = max(maxy, c.first);
    }
    
    for (long long i=miny; i<=maxy; i++){
        string tmp = "";
        for (long long j=minx; j<=maxx; j++){
            tmp += ".";
        }
        answer.push_back(tmp);
    }
    
    for (const auto& c : coords){
        answer[abs(c.first-maxy)][abs(c.second-minx)] = '*';
    }
    
    return answer;
}