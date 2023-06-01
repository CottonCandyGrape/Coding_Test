//https://school.programmers.co.kr/learn/courses/30/lessons/12909
//Implementation, stack

#include<string>
#include<stack>
#include<iostream>

using namespace std;

bool solution(string s)
{
    stack<char> stk;

    for (int i=0; i<s.size(); i++){
        if (s[i]=='(')
            stk.push('(');
        else{
            if (!stk.empty())
                stk.pop();
            else
                return false;
        }
    }
    
    if (!stk.empty())
        return false;

    return true;
}