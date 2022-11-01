#https://www.acmicpc.net/problem/1325
#DFS/BFS, Graph

import sys
input = sys.stdin.readline
from collections import deque

n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    graph[b].append(a)

def bfs(v):
    q = deque([v])
    cnt = 1
    visited = [False]*(n+1)
    visited[v] = True

    while q:
        now = q.popleft()
        for i in graph[now]:
            if not visited[i]:
                visited[i] = True
                q.append(i)
                cnt += 1

    return cnt
    
result = []
maxcnt = 0
for i in range(1, n+1):
    cnt = bfs(i)
    if cnt > maxcnt:
        maxcnt = cnt
        result = []
        result.append(i)
    elif cnt==maxcnt:
        result.append(i)

print(*result)

'''
제한시간도 5초이고 다른사람들 풀이 찾아보니 python3로는 해결이 안되는 듯 했다.
'''