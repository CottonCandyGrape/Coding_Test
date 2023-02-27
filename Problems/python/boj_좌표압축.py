#https://www.acmicpc.net/problem/18870
#Sort

import sys
input = sys.stdin.readline
from collections import defaultdict

n = int(input())
l = list(map(int, input().split()))

sl = sorted(list(set(l)))
dic = defaultdict(int)

for i in range(len(sl)):
    dic[sl[i]] = i

for i in l:
    print(dic[i], end=' ')