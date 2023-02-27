#https://www.acmicpc.net/problem/2178
#BFS

from collections import deque

n, m = map(int, input().split())
mat = [list(map(int, input())) for _ in range(n)]

moves = ((1, 0), (0, 1), (-1, 0), (0, -1))

q = deque([(0,0)])
while q:
    x, y = q.popleft()

    for i, j in moves:
        nx = x + i
        ny = y + j

        if not 0<=nx<n or not 0<=ny<m:
            continue

        if mat[nx][ny] == 0:
            continue

        if mat[nx][ny] == 1:
            mat[nx][ny] = mat[x][y] + 1
            q.append((nx, ny)) #조건에 맞으면 q에 넣기! 자꾸 까먹음..ㅠ

        if nx==n-1 and ny==m-1:
            q.clear()
            break
            
print(mat[n-1][m-1]) 