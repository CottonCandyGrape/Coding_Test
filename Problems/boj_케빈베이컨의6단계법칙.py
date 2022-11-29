#https://www.acmicpc.net/problem/1389
#Floyd-Warshall, BFS

'''
2단계 이상 거쳐야 하는 경우들을 어떻게 플로이드 워셜에 적용해야할지 이해가 안갔다.
여러 노드를 거친다는 것이 이해가 안갔다.
다음의 예로 이해했다.
a->b->c 과정을 거치면 결국 a->c와 같다.
즉, a부터 b까지의 연결 유무와 경로유무는 다르다!(boj_경로찾기 참고)
'''


#Floyd-Warshall 풀이
import sys
input = sys.stdin.readline
inf = int(1e9)

n, m = map(int, input().split())

graph = [[inf]*(n+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        if i==j:
            graph[i][j] = 0

for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i==j:
                continue

            if graph[i][k] and graph[k][j]:
                if graph[i][j]==inf:
                    graph[i][j] = graph[i][k]+graph[k][j]
                else:
                    graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j])

result = [0]*(n+1)
for i in range(1, n+1):
    result[i] = sum(graph[i])

print(result.index(min(result[1:])))

#BFS 풀이
'''
from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def bfs(visited, start):
    nums = [0]*(n+1)
    q = deque([start])
    visited[start] = True
    
    while q:
        now = q.popleft()
        for i in graph[now]:
            if not visited[i]:
                nums[i] = nums[now]+1
                q.append(i)
                visited[i] = True
    return sum(nums)

result = []
for i in range(1, n+1):
    visited = [False]*(n+1)
    result.append(bfs(visited, i))

print(result.index(min(result))+1)
'''