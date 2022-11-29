#https://www.acmicpc.net/problem/1058
#Floyd-Warshall

import sys
input = sys.stdin.readline
inf = int(1e9)

n = int(input())
mat = [list(input()) for _ in range(n)]

graph = [[0]*n for _ in range(n)]
for k in range(n):
    for i in range(n):
        for j in range(n):
            if i==j: continue
            if mat[i][j]=='Y' or (mat[i][k]=='Y' and mat[k][j]=='Y'):
                graph[i][j] = 1

result = 0
for i in graph:
    count = i.count(1)
    result = max(result, count)

print(result)


'''
문제를 보고 플로이드 워셜이라는것은 알았다.
하지만 문제에서 요구하는 값을 카운팅 하는것이 어려웠다.
-> 대칭행렬이니깐 각 행을 사람이라 치면 2-친구의 수는 그 행의 1의 개수와 같다.
'''