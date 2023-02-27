#https://www.acmicpc.net/problem/11724
#DFS/BFS

from collections import deque
import sys
input = sys.stdin.readline #이거로 받아야 bfs에서 시간초과 안남...
sys.setrecursionlimit(10**7) #파이썬은 재귀제한이 걸려있어서 이걸로 조절해줘야한다.

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = [False]*(n+1)

def dfs(graph, s, visited):
    visited[s] = True
    for i in graph[s]:
        if not visited[i]:
            dfs(graph, i, visited)

def bfs(graph, s, visited):
    q = deque([s])
    visited[s] = True
    while q:
        now = q.popleft()
        for i in graph[now]:
            if not visited[i]:
                visited[i] = True
                q.append(i)
        
result = 0
for i in range(1, n+1):
    if not visited[i]:
        #dfs(graph, i, visited)
        bfs(graph, i, visited)
        result += 1
    if len(set(visited[1:]))==1:
        break
        
print(result)