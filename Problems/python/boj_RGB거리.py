#https://www.acmicpc.net/problem/1149
#DP

import sys
input = sys.stdin.readline

n = int(input())
rgb = [list(map(int, input().split())) for _ in range(n)]

for i in range(1, n):
    rgb[i][0] += min(rgb[i-1][1], rgb[i-1][2])
    rgb[i][1] += min(rgb[i-1][2], rgb[i-1][0])
    rgb[i][2] += min(rgb[i-1][0], rgb[i-1][1])

print(min(rgb[n-1]))

'''
이것도 누적합 문제였다...
처음에 재귀로 짠건 가지수가 너무 많고 끝까지 가봐야 알기 때문에 
가지치기도 효과가 없다.
두 번째 for로 구현한건 더 안좋다.
모든 경우의 수를 다 볼수 없기 때문이다.
이 때문에 다시 재귀를 생각했지만 위의 문제로 또 돌아가기 때문에 틀린 방법.
'''