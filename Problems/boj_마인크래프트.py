#https://www.acmicpc.net/problem/18111
#brute-Force

from collections import Counter
import sys
input = sys.stdin.readline

n, m, b = map(int, input().split())
l = []
for _ in range(n):
    l += map(int, input().split()) #1차원 list로 저장하고

dic = dict(Counter(l)) #counter에 넣고 dict에 넣으면 깔끔하게 dict나옴
time = int(1e9) 
for h in range(257):
    maxv, minv = 0, 0

    for k, v in dic.items():
        if k>h:
            maxv += (k-h)*v
        else:
            minv += (h-k)*v

    if minv > maxv+b: # 사용한것보다 쓸수 있는것이 더 적으면 안되니깐 예외 처리
        continue

    count = maxv*2+minv
    if count <= time: # 지금 h에서 구한 시간이 더 짧을때만 시간과 높이 갱신
        time = count  # 안그러면 위의 예외처리를 통과하는 경우 
        height = h    # count가 커도 높이가 갱신됨

print(time, height)