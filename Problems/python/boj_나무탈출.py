#https://www.acmicpc.net/problem/15900
#DFS

import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**5) #여기에 너무 큰 숫자 넣으면 시간초과 날수있다.

n = int(input())
visited = [False]*(n+1)
distance = [0]*(n+1)

graph = [[] for _ in range(n+1)]
for _ in range(n-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    

def dfs(v):
    visited[v] = True

    for i in graph[v]:
        if not visited[i]:
            distance[i] = distance[v]+1
            dfs(i)
            
dfs(1)
count = 0
for i in range(2, n+1):
    if len(graph[i])==1:
        count += distance[i]
        
if count%2==1:
    print('Yes')
else:
    print('No')

'''
n이 최대 500,000이라는 건 dfs가 최대 500,000번 반복될수있다는 말.
2^500,000이 아니고 이 댕청아 ㅠㅠ(왜 이렇게 생각했지ㅠ)

복기
1. 문제 자체를 잘못 걸렸다. 다들 pypy3로 통과한듯...
2. 재귀 제한이 너무 크면 시간 초과될 수 있다.
3. 간단한 거리구하는 dfs문제였는데 너무 Tree에 매몰돼서 어렵게 접근했다.
4. 말이 노드에 겹쳐질 수 있다해서 visited가 의미 없는줄 알았다.
5. 거리를 리프노드'만' 구하려다보니 어려워졌다. (모든 노드의 거리를 구하면 되는데ㅠ)
6. 그래서 distance도 생각 못했던 듯.
너무 간단한 문제였는데 시간 많이 써서 아쉽다 ㅠ
'''