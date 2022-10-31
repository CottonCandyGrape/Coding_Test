#https://www.acmicpc.net/problem/1449
#Greedy

n, l = map(int, input().split())
wl = list(map(int, input().split()))

wl.sort()

start = wl[0]
count = 1

for i in wl[1:]:
    if i in range(start, start+l):
        continue
    else:
        start = i
        count += 1

print(count)

#난 왜 이런 생각을 못할까..? ㅠㅠ