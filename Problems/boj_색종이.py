#https://www.acmicpc.net/problem/2563
#Implementation

import sys
input = sys.stdin.readline

n = int(input())
pl = [tuple(map(int, input().split())) for _ in range(n)]

m = max(map(max, pl)) + 10
mat = [[0]*m for _ in range(m)]

for c, r in pl:
    for i in range(r, r+10):
        for j in range(c, c+10):
            if mat[i][j]==0:
                mat[i][j] = 1
                
result = 0
for i in mat:
    result += sum(i)
print(result)
