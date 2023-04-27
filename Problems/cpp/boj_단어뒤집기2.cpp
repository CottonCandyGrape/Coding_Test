//https://www.acmicpc.net/problem/17413
//Implementation

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    getline(cin, str);
    str += ' ';

    bool reverse = false;
    string tmp = "";
    for (int i=0; i<str.size(); i++){
        if (str[i]=='<' || i==str.size()-1){
            if (tmp.size()){
                string rtmp = "";
                stringstream ss(tmp);
                string token;
                while (getline(ss, token, ' ')){
                    rtmp += string(token.rbegin(), token.rend());
                    rtmp += ' ';
                }
                rtmp.pop_back();
                cout << rtmp;
            }

            tmp = "";
            reverse = true;
        }
        else if (str[i]=='>'){
            reverse = false;
            cout << str[i];
            continue;
        }

        if (reverse){
            cout << str[i];
        }
        else{
            tmp += str[i];
        }
    }
}

//문자열을 하나씩 출력하면서 진행할지
//원본 문자열의 요소들을 바꿔서 마지막에 한번에 출력할지.