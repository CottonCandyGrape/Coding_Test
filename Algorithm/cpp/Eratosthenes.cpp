#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<bool> era;
vector<int> primes;
void eratosthenes(int n){
    era[0]=era[1]=false;
    
    for (int i=2; i<=n; i++){ //primes 배열 쓴다면 n까지!
    //for (int i=2; i<=sqrt(n); i++){ // 안쓴다면 sqrt(n)까지만 해도 ok.
        if (era[i]){
            primes.push_back(i); //이거도 안쓰면 필요 없음.
            for (int j=i*2; j<n+1; j+=i){
                era[j] = false;
            }
        }
    }
}

int main() {
    n = 100;
    era = vector<bool>(n+1, true);
    eratosthenes(n);
}