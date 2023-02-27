#https://www.acmicpc.net/problem/11047
#Greedy

n, k = map(int, input().split())
moneys = [int(input()) for _ in range(n)]
moneys.sort(reverse=True)

result = 0
for m in moneys:
    if k>=m:
        result += k // m
        k %= m
    if k==0: break

print(result)
        