#https://www.acmicpc.net/problem/1051
#Implementation

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
s = min(n, m)
mat = [list(map(int, input().rstrip())) for _ in range(n)]

result = 1
for k in range(2, s+1):
    for i in range(n-k+1):
        for j in range(m-k+1):
            if mat[i][j]==mat[i][j+k-1]==mat[i+k-1][j]==mat[i+k-1][j+k-1]:
                result = max(result, k**2)
    
print(result)