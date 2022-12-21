#https://www.acmicpc.net/problem/9012
#Data Structure

import sys
input = sys.stdin.readline
t = int(input())

for _ in range(t):
    vps = input().rstrip()
        
    stack = []
    for i in vps:
        if i=='(':
            stack.append(i)
        else:
            if stack:
                stack.pop()
            else:
                print('NO')
                break
    else:
        if not stack:
            print('YES')
        else:
            print('NO')