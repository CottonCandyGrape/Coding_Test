#https://www.acmicpc.net/problem/10825
#Sorting

n = int(input())
slist = [input().split() for _ in range(n)]

slist.sort(key=lambda x: (-int(x[1]), int(x[2]), -int(x[3]), x[0]))

for i in slist:
    print(i[0])