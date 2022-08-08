import sys
input = sys.stdin.readline
INF = int(1e9)

def bellman_ford(start):
    # 시작 노드에 대해서 초기화
    dist[start] = 0
    # 전체 n번의 라운드를 반복
    for i in range(n):
        # 매 반복마다 "모든 간선"을 확인
        for j in range(m):
            cur = edges[j][0]
            next_node = edges[j][1]
            cost = edges[j][2]
            # 현재 간선을 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
            if dist[cur] != INF and dist[next_node] > dist[cur] + cost:
                dist[next_node] = dist[cur] + cost
                # n번째 라운드에서도 값이 갱신 된다면 음수 순환 존재
                if i == n - 1:
                    return True
    return False

n, m = map(int, input().split())
edges = []
dist = [INF] * (n+1)

for _ in range(m):
    a, b, c = map(int, input().split())
    edges.append((a, b, c))

negative_cycle = bellman_ford(1) # 1번 노드가 시작 

if negative_cycle:
    print("-1")
else:
    for i in range(2, n+1):
        if dist[i] == INF:
            print("-1")
        else:
            print(dist[i])