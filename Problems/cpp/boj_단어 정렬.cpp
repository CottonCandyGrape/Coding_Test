//https://www.acmicpc.net/problem/1181
//Sort

#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

//set 풀이

struct cmp{
bool operator()(const string& a, const string& b) const{
    if (a.size()==b.size()){
        return a<b;
    }
    else{
        return a.size() < b.size();
    }
}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    set<string, cmp> words;
    string tmp;
    for (int i=0; i<n; i++){
        cin >> tmp;
        words.insert(tmp);
    }

    for (const auto& w : words)
        cout << w << '\n';
}

//vector 풀이

bool cmp(const string& a, const string& b){
    if (a.size()==b.size()){
        return a<b;
    }
    else{
        return a.size() < b.size();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<string> words(n+1);
    string tmp;
    for (int i=0; i<n; i++){
        cin >> words[i];
    }

    sort(words.begin(), words.end()-1, cmp);

    for (int i=0; i<n; i++){
        if (words[i] == words[i+1]) continue;
        cout << words[i] << '\n';
    }
}