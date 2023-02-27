#https://www.acmicpc.net/problem/2210
#DFS

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)

mat = [input().split() for _ in range(5)]
moves = ((1,0), (0,1), (-1,0), (0,-1))

result = set()
def dfs(s, x, y):
    s += mat[x][y]
    if len(s)>=7: 
        result.add(s[:-1])
        return
        
    for mx, my in moves:
        nx = x+mx
        ny = y+my

        if not 0<=nx<5 or not 0<=ny<5:
            continue

        dfs(s,nx,ny)

for i in range(5):
    for j in range(5):
        dfs('',i,j)
        
print(len(result))