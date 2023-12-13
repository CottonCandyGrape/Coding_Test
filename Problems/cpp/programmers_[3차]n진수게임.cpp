//https://school.programmers.co.kr/learn/courses/30/lessons/17687
//Implementation

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string numstr = "0123456789ABCDEF";

string getNum(int n, int num)
{
    string result = "";
    
    while(num>0)
    {
        result += numstr[num%n];
        num /= n;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int limit = t*m;
    int num = 1;
    string nums = "0";
    
    while (nums.size()<limit)
    {
        nums += getNum(n, num);
        num++;
    }
    
    for (int i=p-1; i<limit; i+=m)
        answer += nums[i];
        
    return answer;
}