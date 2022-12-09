#https://www.acmicpc.net/problem/3273
#Sort

import sys
input = sys.stdin.readline

n = int(input())
l = list(map(int, input().split()))
l.sort()
x = int(input())

count = 0

# 투포인터(내꺼보다 깔끔, 신속)
left, right = 0, n-1

while left<right:
    tmp = l[left]+l[right]
    if tmp == x:
        count += 1
        left += 1 #수열의 원소는 서로 다르므로 한번 사용한 포인터는 반드시 옮겨준다.
        right -= 1
    elif tmp>x:
        right -= 1
    elif tmp<x:
        left += 1


# 이진탐색(내풀이)
for i in range(n): #처음에 어리석개 n 대신 n//2을 넣었다. 수열이 대칭적이지 않아서 틀린거다!
    start = i+1
    end = n-1
    val = x-l[i]
    while start<=end:
        mid = (start+end)//2
        if l[mid] == val:
            count += 1
            break
        elif l[mid]>val:
            end = mid-1
        elif l[mid]<val:
            start = mid+1

print(count)