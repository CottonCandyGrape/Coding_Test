#https://www.acmicpc.net/problem/2839
#Greedy, DP

import sys
input = sys.stdin.readline
n = int(input())

#DP
dp = [-1]*5001 #n의 범위 참고. ex)n==4일 때 다음줄에서 에러남. dp[5] 때문에
dp[3], dp[5] = 1, 1

for i in range(3, n+1):
    if dp[i-3]>0 and dp[i-5]>0:
        dp[i] = min(dp[i-3], dp[i-5])+1
    elif dp[i-3]>0 or dp[i-5]>0:
        dp[i] = max(dp[i-3], dp[i-5])+1
        
print(dp[n])

#Greedy
sugar = int(input())

bag = 0
while sugar >= 0 : #while-else 문
    if sugar % 5 == 0 :  # 5의 배수이거나 0이면
        bag += (sugar // 5)  # 5로 나눈 몫을 구해야 정수가 됨
        print(bag)
        break
    sugar -= 3  
    bag += 1  # 5의 배수 또는 0이 될 때까지 설탕-3, 봉지+1
else :
    print(-1)