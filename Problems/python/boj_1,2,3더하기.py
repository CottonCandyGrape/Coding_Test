#https://www.acmicpc.net/problem/9095
#DP

t = int(input())

dp = [0]*10
dp[:3] = [1,2,4]
for i in range(3, 10):
    dp[i] = sum(dp[i-3:i])
for _ in range(t):
    n = int(input())
    print(dp[n-1])

# 규칙 찾기!