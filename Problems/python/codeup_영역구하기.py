#https://codeup.kr/problem.php?id=4572
#DFS/BFS

from collections import deque

m, n, k = map(int, input().split())

klist = [list(map(int, input().split())) for _ in range(k)]
mat = [[0]*n for _ in range(m)]
moves = ((-1, 0), (1, 0), (0, -1), (0, 1))

for i in klist:
    sx, sy, ex, ey = i
    for j in range(sy, ey):
        for k in range(sx, ex):
            mat[j][k] = 7

def bfs(start):
    q = deque([start])
    mat[start[0]][start[1]] = 1
    count = 1

    while q:
        x, y = q.popleft()
        for move in moves:
            nx = x + move[0]
            ny = y + move[1]
            if not 0<=nx<m or not 0<=ny<n:
                continue
            if mat[nx][ny] != 0:
                continue
            if mat[nx][ny] == 0:
                mat[nx][ny] = 1
                count += 1
                q.append((nx, ny))

    return count

area = []
for i in range(m):
    for j in range(n):
        if mat[i][j] == 0:
            area.append(bfs((i, j)))

area.sort()
print(len(area))
print(*area)