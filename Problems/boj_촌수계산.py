#https://www.acmicpc.net/problem/2644
#DFS/BFS

import sys
input = sys.stdin.readline

n = int(input())
x, y = map(int, input().split())
m = int(input())

visited = [False]*(n+1)
graph = [[] for _ in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

result = -1 
def dfs(v, d):
    global result
    if result != -1: return #탈출 조건
        
    visited[v] = True

    if v==y: # 탈출 조건
        result = d
        return

    for i in graph[v]:
        if not visited[i]:
            dfs(i, d+1)
            
        
dfs(x, 0)
print(result)