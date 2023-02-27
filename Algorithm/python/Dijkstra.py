import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

n, e, s = map(int, input().split())
graph = [[] for _ in range(n+1)]
distance = [INF]*(n+1) #방문 처리하는 list를 따로 만들지 않고 distance로 대체

for _ in range(e):
    a, b, c = map(int, input().split()) #a->b로 가는 비용이 c
    graph[a].append((b,c))
    #graph[b].append((a,c)) #무방향 그래프라면 추가해야 함

def dijkstra(start):
    q = []
    distance[start] = 0 #시작 노드는 비용이 0
    heapq.heappush(q, (distance[start], start)) #우선순위 큐

    while q:
        dist, now = heapq.heappop(q) #방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드 선택
        if distance[now] < dist: #이미 방문 처리가 됐다고 간주할 수 있음.
            continue 
        
        for i in graph[now]:#현재(now)와 연결된 노드 중
            cost = dist + i[1]
            if cost < distance[i[0]]: #now를 거쳐 가는 비용이 더 작다면
                distance[i[0]] = cost #갱신
                heapq.heappush(q, (cost, i[0]))
                #큐에 삽입(아직 방문 하지 않았기 때문. 방문했더라도 continue에서 걸림)

dijkstra(s)

for i in range(1, n+1):
    if distance[i] == INF:
        print('Infinity')
    else:
        print(distance[i])

'''
input data
6 11 1
1 2 2
1 3 5
1 4 1
2 3 3
2 4 2
3 2 3
3 6 5
4 3 3
4 5 1
5 3 1
5 6 2
'''