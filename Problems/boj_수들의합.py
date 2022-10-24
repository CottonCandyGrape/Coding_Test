#https://www.acmicpc.net/problem/1789
#Greedy

n = int(input())

result = -1 
num = 1
while n>=0:
    n-=num
    num += 1
    result += 1 
print(result)