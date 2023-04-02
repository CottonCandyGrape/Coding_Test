//https://www.acmicpc.net/problem/1541
//Greedy

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string input;
    cin >> input;

    stringstream ss(input);
    string temp;
    vector<string> splited;
    while (getline(ss, temp, '-')){
        splited.push_back(temp);
    }

    vector<int> sum;
    for (int i=0; i<splited.size(); i++){
        ss.clear();
        ss.str(splited[i]);
        int count = 0; 
        while (getline(ss, temp, '+')){
            count += stoi(temp);
        }
        sum.push_back(count);
    }
    
    int total = sum[0];
    for (int i=1; i<sum.size(); i++){
        total -= sum[i];
    }
    
    cout << total << ' ';
}