#https://www.acmicpc.net/problem/9625
#DP

n = int(input())
dp = [(1, 0)]

for i in range(n+1):
    j, k = dp[i]
    dp.append((k, j+k))
    
print(*dp[n])