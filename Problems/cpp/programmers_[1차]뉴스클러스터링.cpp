//https://school.programmers.co.kr/learn/courses/30/lessons/17677
//Implementation

#include <string>
#include <cctype>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> keys;

void convert(unordered_map<string, int>& smap, const string& str){
    for (int i=0; i<str.size()-1; i++){
        string tmp = "";
        if (isalpha(str[i]) && isalpha(str[i+1])){
            tmp += tolower(str[i]);
            tmp += tolower(str[i+1]);
            smap[tmp] += 1;
            keys.push_back(tmp);
        }
    }
}

int solution(string str1, string str2) {
    int answer=0, uval=0, ival=0;
    unordered_map<string, int> smap1, smap2;
    
    convert(smap1, str1);
    convert(smap2, str2);
    
    uval = keys.size();
    
    if (!uval) return 65536;
    
    for (int i=0; i<keys.size(); i++){
        if (smap1[keys[i]]>0 && smap2[keys[i]]>0){
            uval--; ival++;
            smap1[keys[i]]--; smap2[keys[i]]--;
        }
    }
    
    answer = ((double)ival/uval) * 65536;
    
    return answer;
}