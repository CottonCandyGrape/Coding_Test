#https://www.acmicpc.net/problem/3184
#BFS

from collections import deque
import sys
input = sys.stdin.readline

r, c = map(int, input().split())
mat = [list(input()) for _ in range(r)]
moves = ((1,0), (0,1), (-1,0), (0,-1))
visited = [[False]*c for _ in range(r)]

def swcheck(i, j):
    if mat[i][j]=='o':
        return 1, 0
    elif mat[i][j]=='v':
        return 0, 1
        
    return 0, 0
    
def bfs(x, y):
    visited[x][y] = True
    
    s, w = swcheck(x,y)

    q = deque([(x,y)])
    while q:
        x, y = q.popleft()

        for mx, my in moves:
            nx = x+mx
            ny = y+my

            if not 0<=nx<r or not 0<=ny<c:
                continue

            if mat[nx][ny]=='#' or visited[nx][ny]:
                continue

            a, b = swcheck(nx,ny)
            s += a
            w += b

            visited[nx][ny] = True
            q.append((nx,ny))

    if s>w:
        return s, 0
    else:
        return 0, w
        
s, w = 0, 0    
for i in range(r):
    for j in range(c):
        if mat[i][j] !='#' and not visited[i][j]:
            a, b = bfs(i,j)
            s += a
            w += b
print(s, w)