#https://www.acmicpc.net/problem/1748
#Implementation

n = int(input())
l = len(str(n))

result = 0
for i in range(l-1):
    result += 9*(10**i)*(i+1)

result += (n-10**(l-1)+1)*l
print(result)