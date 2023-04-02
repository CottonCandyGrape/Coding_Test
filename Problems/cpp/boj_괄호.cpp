//https://www.acmicpc.net/problem/9012
//Data Structure

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i=0; i<t; i++){
        string input;
        cin >> input;

        bool flag = false;
        vector<char> stk;

        for (const auto& c : input){
            if (c=='('){
                stk.push_back(c);
            }
            else{
                if (!stk.empty()){
                    stk.pop_back();
                }
                else{
                    cout << "NO" << '\n';
                    flag = true;
                    break;
                }
            }
        }
        
        if (flag) continue;
        
        if(stk.empty())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}
