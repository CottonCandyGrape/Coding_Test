#https://www.acmicpc.net/problem/16173
#DFS/BFS

import sys
input = sys.stdin.readline
from collections import deque

n = int(input())
mat = [list(map(int, input().split())) for _ in range(n)]

moves = ((0,1), (1,0))

#bfs 풀이
def bfs(x, y):
    q = deque([(x,y)])

    while q:
        x, y = q.popleft()
        m = mat[x][y]
        
        for mx, my in moves:
            nx = x + m*mx
            ny = y + m*my
    
            if not 0<=nx<n or not 0<=ny<n:
                continue
    
            if mat[nx][ny]>0:
                q.append((nx, ny))
            elif mat[nx][ny]==-1:
                return "HaruHaru"
    
    return "Hing"

print(bfs(0,0))

#dfs 풀이
result = False
def dfs(x, y):
    global result #끝까지 안들어가고 가지치기 되니 전역변수 사용은 잘한 듯
    if result: return
        
    m = mat[x][y]
    for mx, my in moves:
        nx = x + m*mx
        ny = y + m*my
        
        if not 0<=nx<n or not 0<=ny<n:
            continue

        if mat[nx][ny]>0: 
            dfs(nx, ny)
        elif mat[nx][ny]==-1:
            result = True
            return
dfs(0,0)

if result:
    print("HaruHaru")
else:
    print("Hing")