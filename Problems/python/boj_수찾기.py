#https://www.acmicpc.net/problem/1920
#Binary Search, set 자료형

n = int(input())
a = list(map(int, input().split()))
a.sort()
m = int(input())
b = list(map(int, input().split()))

# set 자료형
for i in b:
    if i in a:
        print(1)
    else:
        print(0)

# 이분 탐색
for i in b:
    flag = False
    start = 0
    end = n-1
    while start<=end:
        mid = (start+end) // 2
        if i==a[mid]:
            flag = True
            break
        elif i>a[mid]:
            start = mid + 1
        else:
            end = mid - 1
    if flag: print(1)
    else: print(0)

'''
set, dict 의 in 연산을 통한 포함 여부 시간 복잡도는 O(1)
'''