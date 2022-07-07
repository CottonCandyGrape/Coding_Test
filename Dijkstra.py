import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

n, e, s = map(int, input().split())
graph = [[] for _ in range(n+1)]
distance = [INF]*(n+1)

for _ in range(e):
    a, b, c = map(int, input().split()) #a->b로 가는 비용이 c
    graph[a].append((b,c))

def dijkstra(start):
    q = []
    distance[start] = 0
    heapq.heappush(q, (0, start)) #우선순위 큐

    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist: continue

        for i in graph[now]:
            cost = dist + i[1] 
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

dijkstra(s)

for i in range(1, n+1):
    if distance[i] == INF:
        print('Infinity')
    else:
        print(distance[i])