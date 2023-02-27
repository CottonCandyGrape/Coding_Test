#https://www.acmicpc.net/problem/16401
#Binary Search

import sys
input = sys.stdin.readline
import bisect

m, n = map(int, input().split())
l = list(map(int, input().split()))
l.sort()

s, e = 1, l[-1]
result = 0
while s<=e:
    mid = (s+e)//2
    idx = bisect.bisect_left(l, mid)
    
    cnt = 0
    for i in range(idx, n): #과자는 자를 수 있으니 이렇게 카운트 해야한다.
        cnt += l[i]//mid
        
    if cnt>=m:
        s = mid+1
        result = mid
    else:
        e = mid-1

print(result)