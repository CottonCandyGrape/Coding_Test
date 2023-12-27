//https://school.programmers.co.kr/learn/courses/30/lessons/84512
//완전탐색, DFS

#include <string>
#include <vector>

using namespace std;

string aeiou = "AEIOU";
int cnt=-1, answer=0;
string target;

void dfs (string w)
{
    cnt++;
    if(w==target){
        answer = cnt;
        return;
    }
    
    if(w.size()==5) return;
    
    for(int i=0; i<5; i++)
        dfs(w+aeiou[i]);
}

int solution(string word) {
    target = word;
    dfs("");
    return answer;
}