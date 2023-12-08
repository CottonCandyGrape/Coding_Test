//https://school.programmers.co.kr/learn/courses/30/lessons/92335
//Implementation

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool prime(long long num){
    if (num<2) return false;
    
    for (long long i=2; i<=sqrt(num); i++)
        if (num%i == 0) return false;
    
    return true;
}

string convert(int num, int k){
    string result; 
    while (num>0){
        result += to_string(num%k);
        num/=k;
    }
    reverse(result.begin(), result.end());
    
    return result;
}

int solution(int n, int k) {
    int answer = 0;
    vector<long long> primes;
    
    string knum = convert(n, k);
    knum += '0';
    
    string tmp = "";
    for (const char k : knum){
        if (k!='0')
            tmp += k;
        else{
            if (tmp.size()) primes.push_back(stoll(tmp));
            tmp = "";
        }
    }
    
    for (const long long p : primes)
        if (prime(p)) answer++; 
    
    return answer;
}

///////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <sstream>

using namespace std;

string itok(int n, int k)
{
    if (k == 10) return to_string(n);
    
    string result = "";
    while (n>0)
    {
        result += to_string(n%k);
        n /= k;
    }
    reverse(result.begin(), result.end());
    
    return result;
}

bool isPrime(long long num)
{
    if (num<=1) return false;
    
    //for (long long i=2; i<=sqrt(num); i++)
    for (long long i=2; i<(long long)sqrt(num)+1; i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<string> pvec;
    
    string knum = itok(n, k);
    istringstream ss(knum);
    string tmp = "";
    while(getline(ss, tmp, '0'))
    {
        if(tmp.size()>0)
            pvec.push_back(tmp);
    }
    
    for (string s : pvec)
    {
        if(isPrime(stoll(s)))
            answer++;
    }
    
    return answer;
}