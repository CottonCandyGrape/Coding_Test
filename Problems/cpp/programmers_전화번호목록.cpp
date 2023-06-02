//https://school.programmers.co.kr/learn/courses/30/lessons/42577
//hash

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> pb) {
    unordered_map<string, bool> pmap;
    
    for (const string& p : pb)
        pmap[p] = true;
    
    for (int i=0; i<pb.size(); i++){
        string pn = "";
        for (int j=0; j<pb[i].size(); j++){
            pn += pb[i][j];
            if(pmap[pn] && pn != pb[i]) //pn이 자기 자신(pb[i])과 같으면 안됨.
                return false;
        }
    }
    
    return true;
}


//substr을 이용한 풀이
bool solution(vector<string> phone_book)
{
    unordered_map<string, int> map;
    for (int i = 0; i < phone_book.size(); i++)
        map[phone_book[i]] = 1;

    for (int i = 0; i < phone_book.size(); i++)
    {
        //이 범위가 phone_number를 자기 자신으로 만들지 않는다.
        for (int j = 0; j < phone_book[i].size(); j++) 
        {
            string phone_number = phone_book[i].substr(0, j);
            if (map[phone_number])
                return false;
    }

    return true;
}
