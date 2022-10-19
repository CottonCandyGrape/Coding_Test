#https://www.acmicpc.net/problem/2667
#BFS

from collections import deque

n = int(input())
mat = [list(map(int, input())) for _ in range(n)]

moves = ((1,0), (-1,0), (0,1), (0,-1))
def bfs(start, m):
    q = deque([start])
    x, y = start
    m[x][y] = -1
    count = 1

    while q:
        x, y = q.popleft()
        for i, j in moves:
            nx = x + i
            ny = y + j
            if not 0<=nx<n or not 0<=ny<n:
                continue
            if m[nx][ny] == 1:
                m[nx][ny] = -1
                q.append((nx, ny))
                count += 1
    return count
        
result = []
for i in range(n):
    for j in range(n):
        if mat[i][j] == 1:
            result.append(bfs((i,j), mat))

result.sort()
print(len(result))
for i in result:
    print(i)
            
        