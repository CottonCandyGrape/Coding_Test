#https://www.acmicpc.net/problem/1654
#Binary Search

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
l = [int(input()) for _ in range(n)]

s = 1
e = max(l)

result = 0
while s<=e:
    tree = 0
    mid = (s+e)//2
    for i in l:
        tree += i//mid

    if tree>=m:
        s = mid+1
        result = mid
    else:
        e = mid-1

print(result)