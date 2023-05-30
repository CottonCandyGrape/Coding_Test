//https://school.programmers.co.kr/learn/courses/30/lessons/84512
//완전탐색, DFS

#include <string>
#include <vector>

using namespace std;

int cnt=-1, answer;
string words = "AEIOU";
string target;

void dfs(int depth, string tmp){
    cnt++;
    
    if (tmp==target) {
        answer = cnt;
        return;
    }
    
    if (depth==words.size()) return;
    
    for (int i=0; i<words.size(); i++)
        dfs(depth+1, tmp+words[i]);
}

int solution(string word) {
    target = word;
    dfs(0, "");
    
    return answer;
}