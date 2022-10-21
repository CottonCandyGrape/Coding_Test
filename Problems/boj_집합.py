#https://www.acmicpc.net/problem/11723
#Implementation

import sys
input = sys.stdin.readline

m = int(input())
S = set()

for _ in range(m):
    cmd = input().rstrip()
    if cmd == 'all':
        S = set([i+1 for i in range(20)])
    elif cmd == 'empty':
        S = set()
    else:
        cmd, n = cmd.split()
        n = int(n) # 이 부분이 문제였다...! int를 str로 쓸경우 메모리 사용량이 더 많다!
        if cmd == 'add':
            if n not in S:
                S.add(n)
        elif cmd == 'remove':
            if n in S:
                S.remove(n)
        elif cmd == 'check':
            if n in S:
                print(1)
            else:
                print(0)
        elif cmd == 'toggle':
            if n in S:
                S.remove(n)
            else:
                S.add(n)