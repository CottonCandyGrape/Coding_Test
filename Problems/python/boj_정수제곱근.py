#https://www.acmicpc.net/problem/2417
#Binary Search

n = int(input())

s = 0
e = n 
result = 0
while s<=e:
    mid = (s+e)//2
    if mid**2>=n:
        result = mid
        e = mid - 1
    else:
        s = mid + 1

print(result)