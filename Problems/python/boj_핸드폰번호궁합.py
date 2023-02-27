#https://www.acmicpc.net/problem/17202
#DP

p = [list(map(int, input())) for _ in range(2)]

dp = []
for i in range(8):
    dp.append(p[0][i])
    dp.append(p[1][i])

for i in range(14):
    for j in range(len(dp)-1):
        dp[j] = (dp[j]+dp[j+1])%10
    dp.pop()
print(''.join(list(map(str, dp))))