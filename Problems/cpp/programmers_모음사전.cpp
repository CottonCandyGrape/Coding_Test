//https://school.programmers.co.kr/learn/courses/30/lessons/84512
//완전탐색, DFS

#include <string>
#include <vector>

using namespace std;

int cnt = 0;
int answer = 0;
string ansWord;
string aeiou = "AEIOU";

void dfs(string word)
{
    if(word == ansWord)
    {
        answer = cnt;
        return; 
    }
    
    if(word.size() > 5)
        return;
    
    cnt++;
    for(int i=0; i<5; i++){
        string w = word + aeiou[i];
        dfs(w);
    }
}

int solution(string word) {
    ansWord = word;
    dfs("");
    return answer;
}