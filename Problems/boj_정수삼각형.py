#https://www.acmicpc.net/problem/1932
#DP

import sys
input = sys.stdin.readline

n = int(input())
l = []
for _ in range(n):
    l.append(list(map(int, input().split())))

for i in range(1, n):
    for j in range(len(l[i])):
        if j==0:
            l[i][j] += l[i-1][0]
        elif j==len(l[i])-1:
            l[i][j] += l[i-1][-1]
        else:
            l[i][j] += max(l[i-1][j-1], l[i-1][j])

print(max(l[-1]))

'''
DP table 변수를 따로 만드려하니 어떻게 만들어야할지 막막했다.
그리고 그것에 맞춰 문제를 풀려다보니 잘못된 접근이 계속 반복됐던 것 같다.

현재 입력을 받은 배열을 그대로 사용하여 풀었다.
그로 인해 행 번호가 증가하며 진행되는 상황을 누적합을 이용하여 표현할 수 있었다.
'''