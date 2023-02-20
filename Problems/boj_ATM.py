#https://www.acmicpc.net/problem/11399
#Greedy, Sort

import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))

l.sort()

num = 0
result = 0 
for i in l:
    num += i
    result += num

print(result)