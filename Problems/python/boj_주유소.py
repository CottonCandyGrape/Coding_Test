#https://www.acmicpc.net/problem/13305
#Greedy

import sys
input = sys.stdin.readline

n = int(input())
roads = list(map(int, input().split()))
citys = list(map(int, input().split()))

total = 0
mincitys = citys[0]
for i in range(n-1):
    if citys[i]<mincitys:
        mincitys = citys[i]
    total += mincitys*roads[i]

print(total)