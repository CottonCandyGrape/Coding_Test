#https://www.acmicpc.net/problem/18352
#BFS, Dijkstra

from collections import deque

#BFS 풀이
n, m, k, x = map(int, input().split())
distance = [-1]*(n+1)
distance[x] = 0

graph = [[] for _ in range(n+1)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

q = deque([x])
while q:
    node = q.popleft()
    for i in graph[node]:
        if distance[i] == -1:
            distance[i] = distance[node] + 1
            q.append(i)
            
if k not in distance:
    print(-1)
else:
    for i in range(1, len(distance)):
        if distance[i] == k:
            print(i)
    
#Dijkstra 풀이
import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

n, e, k, s = map(int, input().split())
graph = [[] for _ in range(n+1)]
dist = [INF]*(n+1)

for i in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)

def dijkstra(start):
    q = []
    dist[start] = 0
    heapq.heappush(q, (0, start))

    while q:
        d, n = heapq.heappop(q)
        if dist[n] < d: continue

        for i in graph[n]:
            cost = d + 1
            if cost < dist[i]:
                dist[i] = cost
                heapq.heappush(q, (cost, i))

dijkstra(s)

result = []
for i in range(1, n+1):
    if dist[i] == k:
        result.append(i)

if result:
    for i in result:
        print(i)
else:
    print(-1)

'''
BFS, Dijkstra로 풀수있는 문제였다.
근데 백준에서 BFS/python3로 채점하면 시간초과 나고 pypy3로 하면 통과가 됐다.
Dijkstra는 그냥 통과가 됐다.
책에서는 모든 간선의 비용이 1이기 때문에 BFS로 풀어도 무방하다고 했다.
'''
    