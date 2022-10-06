#https://www.acmicpc.net/problem/10815
#Binary Search, Data Structure

#set 풀이가 훨씬 빨랐다. 
#set, dict에서 in 사용하여 포함여부 확인하는 시간 복잡도는 O(1)

# set 자료구조 풀이
n = int(input())
slist = list(map(int, input().split()))
m = int(input())
mlist = list(map(int, input().split()))

sset = set(slist)
for i in mlist:
    if i in sset:
        print(1, end=' ')
    else:
        print(0, end=' ')

# Binary Search 풀이
n = int(input())
slist = list(map(int, input().split()))
m = int(input())
mlist = list(map(int, input().split()))

slist.sort()

for i in mlist:
    s = 0
    e = n-1
    flag = False
    while s<=e:
        mid = (s+e) // 2
        if slist[mid] == i:
            flag = True
            break
        elif slist[mid] > i:
            e = mid - 1
        elif slist[mid] < i:
            s = mid + 1
            
    if flag:
        print(1, end=' ')
    else:
        print(0, end=' ')