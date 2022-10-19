#https://www.acmicpc.net/problem/2839
#Greedy, DP

#DP
n = int(input())
dp = [0]*(5001) #n의 범위 참고
dp[3], dp[5] = 1, 1
for i in range(6, n+1):
    if dp[i-3] > 0 and dp[i-5] > 0:
        dp[i] = min(dp[i-3], dp[i-5]) + 1
    elif dp[i-3] > 0 or dp[i-5] > 0:
        dp[i] = max(dp[i-3], dp[i-5]) + 1
        
if dp[n] == 0:
    print(-1)
else:
    print(dp[n])

#Greedy
sugar = int(input())

bag = 0
while sugar >= 0 :
    if sugar % 5 == 0 :  # 5의 배수이면
        bag += (sugar // 5)  # 5로 나눈 몫을 구해야 정수가 됨
        print(bag)
        break
    sugar -= 3  
    bag += 1  # 5의 배수가 될 때까지 설탕-3, 봉지+1
else :
    print(-1)