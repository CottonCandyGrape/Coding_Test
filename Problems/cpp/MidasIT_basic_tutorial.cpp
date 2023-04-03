#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input){
    vector<string> splited;
    stringstream ss(input);
    string token;
    while(getline(ss, token, ' '))
        splited.push_back(token);

    return splited;
}

vector<string> solution(vector<string> history, vector<vector<string>> option, string keyword) {
    vector<string> answer;

    vector<string> options;
    for (const auto& opt : option){
        if (opt[1]=="T")
            options.push_back(opt[0]);
    }

    for (const auto& op : options) {
        if (op=="W"){
            for (const auto& h : history){
                vector<string> words = split(h);
                for (const auto& w : words){
                    if (w==keyword) answer.push_back(h);
                    break;
                }
            }
        }
    }

    if (answer.empty()) answer.push_back("empty");
    
    return answer;
}