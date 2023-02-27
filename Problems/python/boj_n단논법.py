#https://www.acmicpc.net/problem/15723
#Floyd-Warshall, DFS

import sys
input = sys.stdin.readline
#sys.setrecursionlimit(10**9) #최대 26까지만 깊어진다. 그래서 필요 X

offset = ord('a')
midx = 26
graph = [[0]*(midx) for _ in range(midx)]

n = int(input())
for _ in range(n):
    temp = input().split()
    a = ord(temp[0]) - offset
    b = ord(temp[-1]) - offset
    graph[a][b] = 1

#Floyd-Warshall 풀이 start
for k in range(midx):
	for i in range(midx):
		for j in range(midx):
			graph[i][j] = graph[i][j] or (graph[i][k] and graph[k][j])
			#이 부분이 응용이었다. 중간에 몇 개를 거치던 갈수만 있다면 경로는 있다!

m = int(input())
for _ in range(m):
    temp = input().split()
    a = ord(temp[0]) - offset
    b = ord(temp[-1]) - offset

    if graph[a][b]:
        print('T')
    else:
        print('F')
#Floyd-Warshall 풀이 end

#DFS 풀이 start
def dfs(i, j):
    global bool
    if bool: return
        
    for idx, val in enumerate(graph[i]):
        if val==1:
            if idx==j:
                bool = True
                return
            else:
                dfs(idx, j)

m = int(input())
for _ in range(m):
    temp = input().split()
    a = ord(temp[0]) - offset
    b = ord(temp[-1]) - offset

    bool = False
    dfs(a, b)
    if bool:
        print('T')
    else:
        print('F')
#DFS 풀이 end