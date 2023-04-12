//https://school.programmers.co.kr/learn/courses/30/lessons/43165
//DFS

#include <iostream>
#include <vector>

using namespace std;

int answer=0;

void dfs(const vector<int>& nums, const int& target, int depth, int num){
    if (depth==nums.size()){
        if (num==target) answer++;
        return;
    }
    dfs(nums, target, depth+1, num+nums[depth+1]);
    dfs(nums, target, depth+1, num-nums[depth+1]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 1, numbers[0]);
    dfs(numbers, target, 1, -numbers[0]);

    return answer;
}