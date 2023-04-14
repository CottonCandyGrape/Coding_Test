//https://www.acmicpc.net/problem/1331
//Implementation

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> vec(36);
vector<vector<bool>> visited(6, vector<bool>(6, false));

bool check(const pair<int, int>& a, const pair<int, int>& b){
    int x, y, nx, ny;
    x = a.first; y = a.second;
    nx = b.first; ny = b.second;

    if (visited[nx][ny]) return false;

    if ((abs(x-nx)==2 && abs(y-ny)==1) || (abs(x-nx)==1 && abs(y-ny)==2)){
        visited[nx][ny] = true;
        return true;
    }
    else
        return false;
}

bool route(){
    for (int i=1; i<36; i++){
        if (!check(vec[i-1], vec[i])){
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string tmp;
    for (int i=0; i<36; i++){
        cin >> tmp;
        vec[i] = make_pair(tmp[0]-'A', tmp[1]-'1');
    }

    if (check(vec[35], vec[0])){
        visited[vec[0].first][vec[0].second] = true;

        if (!route()) 
            cout << "Invalid";
        else 
            cout << "Valid";
    }
    else
        cout << "Invalid";
}