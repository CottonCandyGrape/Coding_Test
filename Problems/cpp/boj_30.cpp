//https://www.acmicpc.net/problem/10610
//Greedy

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    vector<int> nums;
    int sum=0;
    string num; 
    cin >> num;
    for (const char n : num){
        int tmp = n-'0';
        nums.push_back(tmp);
        sum += tmp;
    }

    sort(nums.rbegin(), nums.rend());
    
    if (nums.back()==0 && sum%3==0){
        for (const int num : nums)
            cout << num;
    }
    else
        cout << -1;
}