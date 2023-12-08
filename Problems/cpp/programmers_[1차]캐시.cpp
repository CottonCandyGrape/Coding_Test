//https://school.programmers.co.kr/learn/courses/30/lessons/17680
//Implementation

#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include <cctype>
#include <algorithm>

using namespace std;

//내 풀이 2
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> clist;

    if (cacheSize == 0) return cities.size() * 5;

    for (string& city : cities)
        transform(city.begin(), city.end(), city.begin(), ::tolower);

    for (const string& city : cities)
    {
        auto it = find(clist.begin(), clist.end(), city);
        if(it!=clist.end()) //hit
        {
            answer++;
            clist.erase(it);
        }
        else //miss
        {
            answer += 5;
            if (clist.size() >= cacheSize)
                clist.pop_front();
        }
        
        clist.push_back(city);
    }

    return answer;
}

//내 풀이 1
int solution(int cacheSize, vector<string> cities) {
    const int ch=1, cm=5;
    
    if (cacheSize==0) return cities.size() * cm;
    
    int answer = 0;
    list<string> slist;
    unordered_map<string, bool> umap;
    
    for (string city : cities){
        transform(city.begin(), city.end(), city.begin(), ::tolower);

        //hit
        if (umap[city]) {
            for (auto it=slist.begin(); it!=slist.end(); it++){
                if (*it == city){
                    slist.erase(it);
                    break;
                }
            }
            
            answer += ch;
        }
        //miss
        else {
            if (slist.size()>=cacheSize){
                umap[slist.front()] = false;
                slist.pop_front();
            }
            umap[city] = true;
            
            answer += cm;
        }
        
        slist.push_back(city);
    }

    return answer;
}


/*
[다른 사람 풀이]
깔끔한데 cacheSize가 적어서 통과인 것 같다. vector에서 erase쓰는게 영 맘에 걸린다.
cacheSize가 컷다면 내 풀이가 더 좋다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(int cacheSize, vector<string> cities) {

    vector <string> q;
    int duration = 0;

    for(vector <string>::iterator it = cities.begin(); it != cities.end(); it++){
        transform(it->begin(), it->end(), it->begin(), ::tolower);

        bool flag = false;
        for(vector<string>::iterator itt = q.begin(); itt != q.end(); itt++){
            if(*itt == *it) {
                flag = true;
                duration +=1;
                q.erase(itt);
                q.push_back(*it);
                break;
            }
        }
        if(!flag) {
            duration +=5;
            if(cacheSize != 0 && q.size() >= cacheSize)
                q.erase(q.begin());
            if(q.size() < cacheSize)
                q.push_back(*it);
        }
    }

    return duration;
}
*/