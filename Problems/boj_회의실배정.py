#https://www.acmicpc.net/problem/1931
#Greedy, Sort

n = int(input())
l = [tuple(map(int, input().split())) for _ in range(n)]
l.sort(key=lambda x: (x[1], x[0])) #빨리 끝나는 시간으로 정렬해야 뒤에 더 고려해볼 회의가 많아 진다.

s, e = l[0][0], l[0][1]
count = 1
for j in range(1, n):
    ns, ne = l[j]
    if e <= ns:
        count += 1
        e = ne
    
print(count)
