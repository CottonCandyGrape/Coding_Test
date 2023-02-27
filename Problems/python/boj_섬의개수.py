#https://www.acmicpc.net/problem/4963
#DFS/BFS

from collections import deque
import sys
input = sys.stdin.readline

moves = ((-1,0), (1,0),(0,-1),(0,1),(-1,-1),(-1,1),(1,1),(1,-1))
def bfs(m, s, v):
    global w, h
    q = deque([s])
    v[s[0]][s[1]] = True

    while q:
        x, y = q.popleft()
        for move in moves:
            nx = x + move[0]
            ny = y + move[1]

            if not 0<=nx<h or not 0<=ny<w:
                continue
                
            if m[nx][ny]==1 and v[nx][ny]==False:
                v[nx][ny] = True
                q.append((nx, ny))
    
while True:
    w, h = map(int, input().split())
    if w==0 and h==0: break

    mat = [list(map(int, input().split())) for _ in range(h)]
    visited = [[False]*w for _ in range(h)]

    result = 0
    for i in range(h):
        for j in range(w):
            if mat[i][j]==1 and visited[i][j]==False:
                bfs(mat, (i,j), visited)
                result += 1
    print(result)