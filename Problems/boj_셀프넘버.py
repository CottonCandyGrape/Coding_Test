#https://www.acmicpc.net/problem/4673
#Implementation

import sys
input = sys.stdin.readline

nums = [True]*10001

for i in range(1, 10001):
    snum = i
    for j in str(i):
        snum += int(j)

    if snum<10001:
        nums[snum] = False

for i in range(1, 10001):
    if nums[i]:
        print(i)