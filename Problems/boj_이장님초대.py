#https://www.acmicpc.net/problem/9237
#Greedy

import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
l.sort(reverse=True)

for i in range(n):
    l[i] += i+1

print(max(l)+1)