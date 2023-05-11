//https://www.acmicpc.net/problem/2477
//Implementation

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> w, h, r;

    int d, l;
    for (int i=0; i<6; i++){
        cin >> d >> l;
        if (d==1 || d==2)
            w.push_back(l);
        else
            h.push_back(l);
        r.push_back(l);
    }
    
    int mw = *max_element(w.begin(), w.end());
    int mh = *max_element(h.begin(), h.end());

    int widx = find(r.begin(), r.end(), mw) - r.begin();
    int hidx = find(r.begin(), r.end(), mh) - r.begin();
    
    int sw = abs(r[(widx+6-1)%6] - r[(widx+6+1)%6]);
    int sh = abs(r[(hidx+6-1)%6] - r[(hidx+6+1)%6]);

    int area = mw*mh - sw*sh;

    cout << area*n;
}