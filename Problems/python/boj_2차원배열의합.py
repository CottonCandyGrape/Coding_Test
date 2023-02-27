#https://www.acmicpc.net/problem/2167
#Implementation, Memoization

n, m = map(int, input().split())
mat = [list(map(int, input().split())) for _ in range(n)]
k = int(input())
dp = [[0]*(m+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, m+1):
        dp[i][j] = mat[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]

for _ in range(k):
    i, j, x, y = map(int, input().split()) 
    print(dp[x][y]-dp[x][j-1]-dp[i-1][y]+dp[i-1][j-1])

'''
1. mat[]으로 dp[]를 어떻게 초기화 할것인가?
2. 구하고자 하는 영역을 dp[]로 어떻게 나타낼 것인가?
각 단계가 잘 파악이 안될때 손으로 그림을 그리고 숫자를 채워가며 규칙을 찾아보자.
'''