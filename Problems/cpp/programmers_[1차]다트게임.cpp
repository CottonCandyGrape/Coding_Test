//https://school.programmers.co.kr/learn/courses/30/lessons/17682
//Implementation

#include <string>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

int bonus(int c){
    if (c=='S') return 1;
    else if (c=='D') return 2;
    else if (c=='T') return 3;
    else return -1;
}

int solution(string str) {
    int answer=0, cursor=0;
    vector<int> ans;
    
    for (int i=0; i<str.size(); i++){
        int e = bonus(str[i]);
        if (e>0){
            int p = stoi(str.substr(cursor, i-cursor));
            p = pow(p, e);
            
            cursor = i+1;
            if (cursor < str.size()){
                if (str[cursor]=='*'){
                    int prev = ans.size()-1;
                    if (prev>-1)
                        ans[prev] *= 2;
                    p *= 2;
                    cursor++;
                }
                else if (str[cursor]=='#'){
                    p *= -1;
                    cursor++;
                }
            }
            
            ans.push_back(p);
        }
    }
    
    answer = accumulate(ans.begin(), ans.end(), 0);
    
    return answer;
}