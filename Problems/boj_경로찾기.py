#https://www.acmicpc.net/problem/11403
#Floyd-Warshall

import sys
input = sys.stdin.readline
inf = int(1e9)

n = int(input())
mat = [list(map(int, input().split())) for _ in range(n)]

for k in range(n):
    for i in range(n):
        for j in range(n):
            if mat[i][k]+mat[k][j]>1:
                mat[i][j] = 1
                
for i in range(n):
    for j in range(n):
        print(mat[i][j], end=' ')
    print()

'''
해설을 보고 문제 이해를 했다... 
노드가 100개 이하이기 때문에 플로이드 워셜이라고 추측할 수 있다.
경로가 있다는 것은 단순 a,b가 연결되어있다가 아니라 a->c->b의 경우도 해당된다.
'''