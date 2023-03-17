//https://www.acmicpc.net/problem/10773
//Implementation

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

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