//https://www.acmicpc.net/problem/2564
//Implementation, 많은 조건 분기

#include <iostream>
#include <vector>

using namespace std;

int n, m, s, total, half, dist=0;
vector<pair<int, int>> info;
vector<int> dists;

int distance(int d, int l){
    if (d==1)
        return l;
    else if (d==2)
        return 2*m + n - l; 
    else if (d==3)
        return 2*(n+m) - l;
    else
        return m+l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> s;

    total = 2*(n+m);
    half = n+m;
    
    int a, b;
    for (int i=0; i<s+1; i++){
        cin >> a >> b;
        info.push_back(make_pair(a, b));
    }

    for (const auto& i : info)
        dists.push_back(distance(i.first, i.second));

    int dong = dists.back();
    for (int i=0; i<s; i++){
        int tmp = abs(dong-dists[i]);
        if (tmp > half)
            dist += total-tmp;
        else
            dist += tmp;
    }
    
    cout << dist;
}

//많은 조건 분기로 푼 코드

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, s, dist=0;
    cin >> m >> n >> s;

    vector<pair<int, int>> info;
    pair<int, int> dong;
    int a, b;
    for (int i=0; i<s; i++){
        cin >> a >> b;
        info.push_back(make_pair(a, b));
    }
    
    cin >> a >> b;
    dong = make_pair(a, b);

    for (const auto& i : info){
        if (dong.first == i.first){
            dist += abs(dong.second-i.second);
        }
        else if (dong.first==1 || dong.first==2){
            if (i.first==3 || i.first==4){
                if (i.first==3)
                    dist += dong.second;
                else
                    dist += m-dong.second;

                if (dong.first==1)
                    dist += i.second;
                else
                    dist += n-i.second;
            }
            else{
                int tmp = n + dong.second + i.second;
                if (tmp > m+n)
                    dist += (2*(n+m) - tmp);
                else
                    dist += tmp;
            }
        }
        else if (dong.first==3 || dong.first==4){
            if (i.first==1 || i.first==2){
                if (i.first==1)
                    dist += dong.second;
                else
                    dist += n-dong.second;

                if (dong.first==3)
                    dist += i.second;
                else
                    dist += m-i.second;
            }
            else{
                int tmp = m + dong.second + i.second;
                if (tmp > m+n)
                    dist += (2*(n+m) - tmp);
                else
                    dist += tmp;
            }
        }
    }

    cout << dist;
}