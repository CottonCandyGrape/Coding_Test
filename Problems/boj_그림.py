#https://www.acmicpc.net/problem/1926
#BFS/DFS

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7) #재귀로 풀거면 꼭 넣고 풀자

n, m = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(n)]

visited = [[0]*m for _ in range(n)]
moves = ((-1,0), (1,0), (0,1), (0,-1))

def dfs(s, v):
    global depth
    #depth = max(depth, d) #중간에 이렇게 넣으면 카운트 안되는게 생긴다.
    depth += 1
    x, y = s[0], s[1]
    v[x][y] = 1 
    for mx, my in moves:
        nx = x + mx
        ny = y + my

        if not 0<=nx<n or not 0<=ny<m:
            continue

        if mat[nx][ny]==1 and v[nx][ny]==0:
            dfs((nx,ny), v)

count, result = 0, 0
for i in range(n):
    for j in range(m):
        if mat[i][j]==1 and visited[i][j]==0:
            depth = 0
            dfs((i, j), visited)
            result = max(result, depth)
            count += 1

print(count)
print(result)

#ㅗ 모양에서 제일 윗부분에서 시작하고 오른쪽으로 갔다가 왼쪽으로 간다고 생각하면 
#맨 오른쪽이 max카운트일테고 이게 왼쪽 카운트 하러가면 
#왼쪽은 depth가 더 낫기 때문에 카운팅이 안된다.