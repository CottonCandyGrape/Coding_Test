#https://www.acmicpc.net/problem/1012
#BFS

from collections import deque

moves = ((1,0), (-1,0), (0,1), (0,-1))
def bfs(start, m, r, c):
    q = deque([start])
    x, y = start
    m[x][y] = -1
    count = 1

    while q:
        x, y = q.popleft()
        for i, j in moves:
            nx = x + i
            ny = y + j
            if not 0<=nx<r or not 0<=ny<c:
                continue
            if m[nx][ny] == 1:
                m[nx][ny] = -1
                q.append((nx, ny))
                count += 1

t = int(input())
result = []
for i in range(t):
    n, m, k = map(int, input().split())

    mat = [[0]*m for i in range(n)]
    for i in range(k):
        x, y = map(int, input().split())
        mat[x][y] = 1

    count = 0
    for i in range(n):
        for j in range(m):
            if mat[i][j] == 1:
                bfs((i, j), mat, n, m)
                count += 1
    result.append(count)

for i in result:
    print(i)