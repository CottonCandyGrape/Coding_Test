#https://www.acmicpc.net/problem/2477
#Implementation

import sys
input = sys.stdin.readline

k = int(input())

w = []
h = []
rect = []
for _ in range(6):
    a, b = map(int, input().split())
    if a==1 or a==2:
        w.append(b)
        rect.append(b)
    else:
        h.append(b)
        rect.append(b)

widx = rect.index(max(w))
hidx = rect.index(max(h))
sw = abs(rect[(widx+6-1)%6] - rect[(widx+1)%6])
sh = abs(rect[(hidx+6-1)%6] - rect[(hidx+1)%6])

hexagon = max(w)*max(h) - sw*sh
result = hexagon*k

print(result)