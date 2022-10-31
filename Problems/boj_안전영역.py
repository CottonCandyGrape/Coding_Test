#https://www.acmicpc.net/problem/2468
#DFS/BFS

from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
maxw = 0
mat = []
for _ in range(n):
    mat.append(list(map(int, input().split())))
    maxw = max(maxw, max(mat[-1]))
    
moves = ((-1,0), (1,0),(0,-1),(0,1))

def bfs(m, s, w, v):
    q = deque([s])
    v[s[0]][s[1]] = 1

    while q:
        x, y = q.popleft()
        for move in moves:
            nx = x + move[0]
            ny = y + move[1]

            if not 0<=nx<n or not 0<=ny<n:
                continue
            if v[nx][ny]==1:
                continue
            if m[nx][ny]>w:
                v[nx][ny] = 1
                q.append((nx,ny))
            
result = 0
for w in range(maxw): #처음에 최소값도 계산했지만 비가 안올경우를 고려해 0부터 maxw-1까지.
    count = 0
    visited = [[0]*n for _ in range(n)] #매번 visited를 새로 초기화 해줘야한다.
    for i in range(n):
        for j in range(n):
            if visited[i][j]==0 and mat[i][j]>w:
                bfs(mat, (i,j), w, visited)
                count += 1
    result = max(result, count)
    
print(result)