//https://school.programmers.co.kr/learn/courses/30/lessons/17686
//Implementation

#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

bool cmp (const vector<string>& a, const vector<string>& b)
{
    string lstr = a[0];
    string rstr = b[0];
    transform(lstr.begin(), lstr.end(), lstr.begin(), ::tolower);
    transform(rstr.begin(), rstr.end(), rstr.begin(), ::tolower);
    int lnum = stoi(a[1]);
    int rnum = stoi(b[1]);
    
    if (lstr == rstr)
        return lnum < rnum;
    return lstr < rstr;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> split;
    
    for (int i=0; i<files.size(); i++)
    {
        vector<string> tmp;
        string head = "", num = "";
        int idx = 0;
        for (; idx<files[i].size(); idx++)
        {
            if (!isdigit(files[i][idx]))
                head += files[i][idx];
            else break;
        }
        
        //stoi에서 최초로 숫자로 인식된 부분만 int로 바꾸기 때문에 숫자idx ~ 끝idx까지 넘겨도 된다.
        num = files[i].substr(idx);
        
        tmp.push_back(head);
        tmp.push_back(num);
        split.push_back(tmp);
    }
    
    stable_sort(split.begin(), split.end(), cmp);
    
    for (const auto& s : split)
        answer.push_back(s[0] + s[1]);
    
    return answer;
}