#https://www.acmicpc.net/problem/1388
#DFS

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
mat = [list(input().rstrip()) for _ in range(n)]

def dfs(d,x,y):
    mat[x][y]=0
    if d=='-':
        if not 0<=y+1<m:
            return
        if d==mat[x][y+1]:
            dfs(d,x,y+1)
    else:
        if not 0<=x+1<n:
            return
        if d==mat[x+1][y]:
            dfs(d,x+1,y)

count = 0    
for i in range(n):
    for j in range(m):
        if mat[i][j]!=0:
            dfs(mat[i][j],i,j)
            count += 1

print(count)