//23 LG전자 신입공채 샘플문제
//brute force?

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;	// 건물의 층수
int X[100+10]; // 층별 공급지의 위치
int Y[100+10]; // 층별 소비지의 위치
 
void InputData(void){
	cin >> N;
	for(int i=0; i<N; i++) cin >> X[i] >> Y[i];
}

int getIdx(const vector<pair<int, int>>& f, const vector<bool>& c){
	for (int i=0; i<N; i++){
		if (!c[f[i].second]) return i;
	}
	return -1;
}

int main(void){
	int ans = 0;
	InputData(); // 입력함수
	
	vector<bool> check(N, false); //해결된 층 정보
	vector<pair<int, int>> floor(N); //층idx와 길이
	for (int i=0; i<N; i++){
		floor[i].first = Y[i]-X[i];
		floor[i].second = i;
	}
	sort(floor.rbegin(), floor.rend()); //제일 긴층부터 정렬
	
	int idx = getIdx(floor, check); //제일 길면서 아직 해결 되지 않은 층.
	while (idx!=-1){
		int count = 0;
		vector<int> pos;
		for (int i=X[idx]; i<=Y[idx]; i++){ //제일 긴층의 공급지-소비지
			int tmp = 0;
			vector<int> tmpv;
			for (int j=0; j<N; j++){
				if (X[j]<=i && Y[j]>=i){
					tmpv.push_back(j);
					tmp++;
				}
			}

			if (tmp>count){
				pos = tmpv; //제일 많아서 갱신될때의 층 정보 저장.
				count = tmp; //몇개 층 해결했는지.
			}
		}

		for (int i=0; i<pos.size(); i++)
			check[pos[i]] = true;
		
		idx = getIdx(floor, check);
		ans++;
	}

	cout << ans << endl;//출력
	return 0;
}