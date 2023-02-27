#https://www.acmicpc.net/problem/9655
#DP

n = int(input())

dp = [0, 1, 2]
for i in range(3, n+1):
    dp.append(min(dp[i-1], dp[i-3])+1)
if dp[n] % 2 == 0:
    print('CY')
else:
    print('SK')



'''
dp[2]가 왜 2인지 이해 안갔었는데 
1개 또는 3개만 가져갈 수 있으니깐 
돌이 2개면 무조건 턴이 2번일 수 밖에 없다!
'''
'''
처음 짠 코드 앞부분
dp = [0]*(n+1) 
dp[0], dp[1], dp[2] = 0, 1, 2 
이렇게 짜면  n이 1일 때 Error

대안은 위 코드 처럼 짜던가 다음 줄 처럼.
dp = [0] * 1001 (N의 범위: 1~1000)
'''


