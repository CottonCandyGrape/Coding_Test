//https://www.acmicpc.net/problem/2504
//Implementation, stack


#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int answer=0, temp=1;
    vector<int> stk;

    string input;
    cin >> input;

    for (int i=0; i<input.size(); i++){
        if (input[i]=='('){
            stk.push_back(input[i]);
            temp *= 2;
        }
        else if (input[i]=='['){
            stk.push_back(input[i]);
            temp *= 3;
        }
        else if (input[i]==')'){
            if (stk.empty() || stk.back()!='('){
                answer = 0;
                break;
            }
            else if (input[i-1]=='('){
                answer += temp;
            } 
            temp /= 2;
            stk.pop_back();
        }
        else{ //c==']'
            if (stk.empty() || stk.back()!='['){
                answer = 0;
                break;
            }
            else if (input[i-1]=='['){
                answer += temp;
            } 
            temp /= 3;
            stk.pop_back();
        }
    }

    if (!stk.empty()){
        cout << "0";
    }
    else{
        cout << answer;
    }
}
