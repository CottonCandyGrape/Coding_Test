//https://www.acmicpc.net/problem/1966
//Implementation

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int n, m;
        cin >> n >> m;
        
        deque<int> deq;
        for (int j=0; j<n; j++){
            int val;
            cin >> val;
            deq.push_back(val);
        }
        
        int count = 1;
        while (deq.size()){
            int max = *max_element(deq.begin(), deq.end()); //이건 무조건 pop_left담에 와야한다.
            if (deq.front()<max){
                deq.push_back(deq.front());
            }
            else{
                if (m==0){
                    cout << count << '\n';
                    break;
                }
                count++;
            }
            deq.pop_front(); // 근데 max가 else 경우에만 바뀌기 때문에 그 경우에 max를 구한다면 if-else 두군데에서 이 코드가 들어가야 한다.
            m = (deq.size()+m-1)%deq.size(); //size로 안해줄 경우 else 경우에서 n--해줘야하는데 좀 지저분에 보여서 이렇게 한다.
        }
    }
}