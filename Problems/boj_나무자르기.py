#https://www.acmicpc.net/problem/2805
#Binary Search

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
l = list(map(int, input().split()))

s = 0
e = int(1e9) #max(l) 쓰면 시간초과 났다.

result = 0
while s<=e:
    tree = 0
    mid = (s+e)//2
    for i in l:
        if i>mid:
            tree += i-mid

    if tree>=m:
        s = mid+1
        result = mid
    else:
        e = mid-1

print(result)