#https://codeup.kr/problem.php?id=4697
#DFS/BFS

from collections import deque

n = int(input())
mat = [list(map(int, input().split())) for _ in range(n)]
moves = ((-1, 0), (1, 0), (0, -1), (0, 1))

maxh = max(sum(mat, []))
minh = min(sum(mat, []))

def bfs(start, w):
    q = deque([start])
    if vmat[start[0]][start[1]] == 0:
        vmat[start[0]][start[1]] = 1

    while q:
        x, y = q.popleft()

        for move in moves:
            nx = x + move[0]
            ny = y + move[1]
            if not 0<=nx<n or not 0<=ny<n:
                continue
            if vmat[nx][ny] == 1:
                continue
            if mat[nx][ny] > w:
                vmat[nx][ny] = 1
                q.append((nx, ny))

mcount = 0
if maxh==minh:
    print(1)
else:
    for w in range(maxh-1,minh-1,-1):
        vmat = [[0]*n for _ in range(n)] # 방문 처리 배열을 w 바뀔때마다 갱신해야 했는데 이게 최선 인가?!?!
        count = 0
        for i in range(n):
            for j in range(n):
                if mat[i][j] > w and vmat[i][j]==0:
                    bfs((i, j), w)
                    count += 1
        mcount = max(mcount, count)

    print(mcount)
            
        
    
