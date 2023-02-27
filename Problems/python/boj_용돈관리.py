#https://www.acmicpc.net/problem/6236
#Binary Search

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
l = [int(input()) for _ in range(n)]

s = max(l) #이것보다 작으면 어느 하루도 보낼 수 없다.
e = sum(l) #m==1인 경우 가장 크다

result = 0
while s<=e:
    k = (s+e)//2

    count = 1
    tmp = k
    for i in l:
        if tmp<i:
            tmp = k
            count += 1
        tmp -= i

    if count>m:
        s = k+1
    else:
        e = k-1
        result = k

print(result)