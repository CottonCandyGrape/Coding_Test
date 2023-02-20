#https://www.acmicpc.net/problem/1931
#Greedy, Sort

import sys
input = sys.stdin.readline

n = int(input())

l = [tuple(map(int, input().split())) for _ in range(n)] #빨리 끝나는 시간으로 정렬해야 뒤에 더 고려해볼 회의가 많아진다.
l.sort(key=lambda x: (x[1],x[0])) 

count = 1
e = l[0][1]
for i in l[1:]:
    if e<=i[0]:
        count += 1
        e = i[1] 
print(count)