#https://www.acmicpc.net/problem/1417
#Greedy, Implementation

import heapq
import sys
input = sys.stdin.readline

n = int(input())
l = [int(input()) for _ in range(n)]

da = l[0]
q = []
for i in l[1:]:
    heapq.heappush(q, -i)

count = 0
if q:
    while da<=-q[0]:
        num = heapq.heappop(q)
        num += 1
        heapq.heappush(q, num)
        da += 1
    
        count += 1
            
print(count)
