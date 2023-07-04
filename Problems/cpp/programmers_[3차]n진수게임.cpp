//https://school.programmers.co.kr/learn/courses/30/lessons/17687
//Implementation

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string nums = "0123456789ABCDEF";

string getn(int n, int k){
    string result = "";
    while (n>0){
        result += nums[n%k];
        n /= k;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    int limit = t*m;
    int num=1;
    string tmp = "0";
    
    while (true){
        tmp += getn(num, n);
        if (tmp.size()>limit) break;
        num++;
    }
    
    for (int i=p-1; i<limit; i+=m)
        answer += tmp[i];
    
    return answer;
}