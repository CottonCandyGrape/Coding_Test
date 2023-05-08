//https://www.acmicpc.net/problem/2941
//Implementation

#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string> cro ={ "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    string str;
    cin >> str;

    for (const string& c : cro){
        while (true){
            size_t pos = str.find(c);
            if (pos!=string::npos)
                str.replace(pos, c.size(), "A");
            else 
                break;
        }
    }
    
    cout << str.size();
}