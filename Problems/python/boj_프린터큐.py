#https://www.acmicpc.net/problem/1966
#Implemetation

from collections import deque

k = int(input())
result = []
for _ in range(k):
    n, m = map(int, input().split())
    if n==1:
        p = int(input())
        result.append(1)
        continue
    p = list(map(int, input().split()))

    q = deque(p)
    cnt = 0
    while True:
        doc = q[0] #여기서 popleft()를 했었는데 
        if doc >= max(q): #그러면 q가 비었을 경우 max(q)에서 ValueError.
            cnt += 1
            if m == 0: 
                result.append(cnt)
                break
        else:
            q.append(doc)
        q.popleft()
        m = (m-1+len(q))%len(q)

for i in result:
    print(i)