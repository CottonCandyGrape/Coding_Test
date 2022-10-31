#https://www.acmicpc.net/problem/11725
#DFS/BFS

import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

n = int(input())
tree = [[] for _ in range(n+1)]
for i in range(1, n):
    a, b = map(int, input().split())
    tree[a].append(b)
    tree[b].append(a)

parents = [0]*(n+1)

def dfs(n):
    for i in tree[n]:
        if parents[i]==0:
            parents[i] = n
            dfs(i)
            
dfs(1)

for i in range(2, n+1):
    print(parents[i])

'''
입력은 어차피 트리 구조에 맞게 들어올거고...
루트를 지정해 줬으니 루트부터 DFS하면 처음 방문하는 노드의 부모는 직전의 노드 번호
'''
