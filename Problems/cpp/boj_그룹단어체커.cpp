//https://www.acmicpc.net/problem/1316
//Implementation

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