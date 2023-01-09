#https://www.acmicpc.net/problem/2075
#Sort, Heapq

import sys
input = sys.stdin.readline
import heapq

n = int(input())
l = list(map(int, input().split()))

q = []
for i in l:
    heapq.heappush(q, i)

for _ in range(n-1):
    l = list(map(int, input().split()))
    for i in l:
        if i>q[0]:
            heapq.heappop(q)
            heapq.heappush(q,i)

print(q[0])

'''
메모리 초과를 어떻게 해결해야 할지 몰랐고 heapq를 사용할 생각을 못했다. 
N번째로 큰 이라는 걸 봤을때 heapq를 생각해야겠다.
메모리 초과는 사용되는 자료구조의 크기를 일정 수준으로 유지하는 방법을 써야겠다.
상당히 어려웠다... 풀이 안봤으면 못풀었을듯...
'''