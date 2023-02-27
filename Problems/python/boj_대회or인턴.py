#https://www.acmicpc.net/problem/2875
#Greedy

n, m, k = map(int, input().split())

teams = 0
while n>=2 and m>=1 and n+m>=3+k:
    n -= 2
    m -= 1
    teams += 1

print(teams)