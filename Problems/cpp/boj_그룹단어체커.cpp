//https://www.acmicpc.net/problem/1316
//Implementation

//23/05/22
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, cnt=0;
    cin >> n;

    for (int i=0; i<n; i++){
        string word, tmp;
        cin >> word;

        tmp = word[0];
        for (int i=1; i<word.size(); i++){
            if (word[i-1]!=word[i]){
                tmp += word[i];
            }
        }

        bool flag = true;
        for (int i=0; i<tmp.size(); i++){
            if (count(tmp.begin(), tmp.end(), tmp[i])!=1){
                flag = false;
                break;
            }
        }

        if (flag) cnt++;
    }

    cout << cnt;
}

/*
//23/04/14
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    int result = n;
    vector<string> strings(n);
    for (int i=0; i<n; i++)
        cin >> strings[i]; 

    for (int i=0; i<n; i++){
        string tmp = strings[i];
        map<char, int> cmap;
        cmap[tmp[0]]++;
        for (int j=1; j<tmp.size(); j++){
            if (tmp[j] != tmp[j-1]){
                if (cmap[tmp[j]]) {
                    result--;
                    break;
                }
                else
                    cmap[tmp[j]]++;
            }
        }
    }

    cout << result;
}
*/