#https://www.acmicpc.net/problem/2847
#Greedy

n = int(input())
l = [int(input()) for _ in range(n)]

result = 0
for i in range(n-1, 0, -1):
    while l[i]<=l[i-1]:
        l[i-1] -= 1
        result += 1
print(result)

#이건 쉬웠다 ㅠ