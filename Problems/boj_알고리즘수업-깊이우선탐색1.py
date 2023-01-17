#https://www.acmicpc.net/problem/24479
#DFS

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

n, m, r = map(int, input().split())
visited = [0]*(n+1)
graph = [[] for _ in range(n+1)]
for _ in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

for i in range(1, n+1):
    graph[i].sort()

count = 1
def dfs(s):
    global count
    visited[s] = count 
    
    for i in graph[s]:
        if not visited[i]:
            count += 1
            dfs(i)

dfs(r)
for i in range(1, n+1):
    print(visited[i])
    
'''틀린 코드
def dfs(d,s):
    visited[s] = d 
    
    for i in graph[s]:
        if not visited[i]:
            dfs(d+1, i)
'''
'''틀린 이유
문제는 노드의 방문 순서를 구하는 것이다.
근데 d를 저런식으로 넘겨주게 되면
방문 순서가 아닌 그 층수를 반영하게 된다.
ex) 1층 : 1, 2층:2, 4, 3층: 3를 오름차순으로 방문하게 되면
1,2,3,4 순으로 방문하는데 틀린 코드대로 하면
1,2,3,3 으로 된다. 3을 방문하고 다시 2층으로 와서 d+1 하기 때문
'''



