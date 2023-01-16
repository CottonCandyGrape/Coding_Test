#https://www.acmicpc.net/problem/11497
#Greedy

import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    l.sort()

    #1번
    h = 0
    for i in range(2, n):
        h = max(h, abs(l[i]-l[i-2]))
    #1번

'''
    #2번
    a = [] 
    for i in range(0,n,2):
        a.append(l[i])
        
    b = []
    for i in range(1,n,2):
        b.append(l[i])

    nl = a+b[::-1]
    h = 0
    for i in range(n):
        h = max(h, abs(nl[i-1]-nl[i]))
    #2번
'''
        
    print(h)

'''
이 문제는 굳이 list를 다시 배열하지 않아도 
idx가 2차이 나는 원소들만 비교하면 되는 문제였다.
'''
