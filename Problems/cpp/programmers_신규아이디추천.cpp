//school.programmers.co.kr/learn/courses/30/lessons/72410
//Implementation

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string tmp = "";
    
    //1단계
    for (char &n : new_id)
    {
        if (isupper(n)) 
            n = tolower(n);
    }
    
    //2단계
    for (char n : new_id)
    {
        if ('a'<=n && n<='z' || '0'<=n && n<='9' || n=='-' || n=='_' || n=='.')
            tmp += n;
    }
    new_id = tmp;
    
    //3단계
    tmp = new_id.front();
    for (int i=1; i<new_id.size(); i++)
    {
        if (new_id[i] == '.' && tmp.back()=='.')
            continue;
        tmp += new_id[i];
    }
    new_id = tmp;
    
    //4단계
    if (new_id.front() == '.')
        new_id.erase(new_id.begin());
    if (new_id.back() == '.')
        new_id.pop_back();
    
    //5단계
    if (new_id.size()==0)
        new_id = "a";

    //6단계
    if(new_id.size()>=16)
        new_id = new_id.substr(0, 15);
    if (new_id.back() == '.')
        new_id.pop_back();
    
    //7단계
    while(new_id.size()<=2)
        new_id += new_id.back(); 
    
    answer = new_id;
    return answer;
}