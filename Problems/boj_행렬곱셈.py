#https://www.acmicpc.net/problem/2740
#Implementation

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]

m, k = map(int, input().split())
B = [list(map(int, input().split())) for _ in range(m)]
B = list(map(list, zip(*B))) #row, col 뒤집어서

for a in A:
    tmp = []
    for b in B:
        val = 0
        for c in range(len(a)):
            val += a[c]*b[c] #차례대로 곱했다.
        tmp.append(val)
    print(*tmp)

'''
row, col 뒤집히는거 헷갈려서 B row, col 먼저 뒤집어서 풀었다.
인덱싱이 너무 헷갈려서 2차원으로는 못풀었다.
근데 난 내 풀이가 이해하기 더 쉽다.
'''
'''
다른사람 깔끔 풀이 https://my-coding-notes.tistory.com/95
A의 col이 B의 row
B의 col만큼 연산해야하니깐 가운데 for문이 B의 col
'''
