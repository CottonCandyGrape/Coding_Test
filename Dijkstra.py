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
        #1)INF에서 갱신되니깐 방문했다면 보통 dist보다 작다.
        #2) 현재(now)의 distance값보다 dist가 크다면 볼필요도 없다.

        for i in graph[now]:
            cost = dist + i[1] 
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0])) 
                #distance를 초기화 or 갱신해야 어디가 더 빨리갈수있는지 알지!

dijkstra(s)

for i in range(1, n+1):
    if distance[i] == INF:
        print('Infinity')
    else:
        print(distance[i])