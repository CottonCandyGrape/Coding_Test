//https://school.programmers.co.kr/learn/courses/30/lessons/43163
//DFS,BFS

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool change(string a, string b){
    int cnt=0;
    for (int i=0; i<a.size(); i++){
        if (a[i]!=b[i]) cnt++;
    }
    if (cnt==1)
        return true;
    else
        return false;
}


//BFS 풀이
int bfs(int depth, string b, const string t, const vector<string>& words){
    deque<pair<string, int>> dq;
    dq.push_back(make_pair(b, 0));
    
    if (find(words.begin(), words.end(), t) == words.end())
        return 0;
    
    while (!dq.empty()){
        string word = dq.front().first;
        int depth = dq.front().second;
        dq.pop_front();
        
        for (const string& w : words){
            if (change(word, w)){
                if (w==t) 
                    return depth+1;
                else
                    dq.push_back(make_pair(w, depth+1));
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    answer = bfs(0, begin, target, words);
    
    return answer;
}


//DFS 풀이
int answer = 51;
vector<bool> visit;
void dfs(int depth, string b, const string t, const vector<string>& w){
    if (answer<depth) return;
    
    if (b==t)
        answer = depth;
    
    for (int i=0; i<w.size(); i++){
        if (change(b, w[i]) && !visit[i]){
            visit[i] = true;
            dfs(depth+1, w[i], t, w);
            visit[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    visit.resize(words.size(), false);
    
    dfs(0, begin, target, words);
    
    if (answer == 51) 
        return 0;
    
    return answer;
}