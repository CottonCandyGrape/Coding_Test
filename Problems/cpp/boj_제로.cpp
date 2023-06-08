//https://www.acmicpc.net/problem/10773
//Implementation

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

//accumulate 사용 X. 이게 더 빠름
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, tmp, result=0;
    cin >> k;

    vector<int> vec;
    for (int i=0; i<k; i++){
        cin >> tmp;
        if (tmp){
            result += tmp;
            vec.push_back(tmp);
        }
        else{
            result -= vec.back();
            vec.pop_back();
        }
    }

    cout << result;
}

//accumulate 사용 풀이
int main() {
    int k;
    cin >> k;
    vector<int> vec;
    int temp;
    for (int i=0; i<k; i++){
        cin >> temp;
        if (temp)
            vec.push_back(temp);
        else
            vec.pop_back();
    }
    cout << accumulate(vec.begin(), vec.end(), 0);
    
    return 0;
}