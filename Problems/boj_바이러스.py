#https://www.acmicpc.net/problem/2606
#BFS

from collections import deque

n = int(input())
e = int(input())
graph = [[] for _ in range(n+1)]
visited = [False]*(n+1)
for i in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

q = deque([1])
visited[1] = True

while q:
    now = q.popleft()
    for i in graph[now]:
        if not visited[i]:
            visited[i] = True
            q.append(i)

print(visited.count(True)-1)