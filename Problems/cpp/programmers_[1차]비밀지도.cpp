//https://school.programmers.co.kr/learn/courses/30/lessons/17681
//Implementation

#include <bitset>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for (int i=0; i<n; i++){
        string x = bitset<16>(arr1[i] | arr2[i]).to_string();
        
        string tmp = "";
        for (int j=16-n; j<16; j++){
            if (x[j]=='1')
                tmp += "#";
            else
                tmp += " ";
        }
        
        answer.push_back(tmp);
    }
    
    return answer;
}