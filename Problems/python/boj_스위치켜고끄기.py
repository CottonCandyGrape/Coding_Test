#https://www.acmicpc.net/problem/1244
#Implementation

import sys
input = sys.stdin.readline

count = int(input())
switch = list(map(int, input().split()))
snum = int(input())
slist = [list(map(int, input().split())) for _ in range(snum)]

def toggle(l, i):
    if l[i] == 1:
        l[i] = 0
    else:
        l[i] = 1

for s, n in slist:
    if s==1:
        for i in range(n, count+1, n):
            toggle(switch, i-1)
    else:
        l = n-2
        r = n
        while l>-1 and r<count:
            if switch[l]!=switch[r]:
                break
            l = l-1
            r = r+1
            
        for i in range(l+1, r):
            toggle(switch, i)

for i in range(0, count, 20):
    print(*switch[i:i+20])