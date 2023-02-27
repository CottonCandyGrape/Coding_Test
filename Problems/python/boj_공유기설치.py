#https://www.acmicpc.net/problem/2110
#Binary Search, Parametric Search

import sys
input = sys.stdin.readline

n, c = map(int, input().split())
l = [int(input()) for _ in range(n)]
l.sort()

s = 1 # 최소 거리 : 배열의 첫번째 원소가 아닌 1
e = l[-1] - l[0] # 최대 거리 : 제일 작은 원소와 큰 원소의 차이

result = 0
while s<=e:
    mid = (s+e)//2
    val = l[0]
    cnt = 1 # 처음에 1개 두니깐 1부터 시작
    for i in range(1, n):
        if l[i]>=mid+val:
            val = l[i]
            cnt += 1
    if cnt>=c:
        s = mid+1 
        result = mid
    else:
        e = mid-1

print(result)


'''
첨부터 공유기 개수를 c개로 하고 hlist 에서 c개만큼 뽑는 조합의 방법을 생각했다.
역시나 비효율적이어서 틀림.
간격을 조절하면서 공유기 개수를 count 하는게 관건이었음.
이진 탐색을 어떻게 적용해야 하는지가 중요하다.
이건 문제를 많이 풀어봐야겠다.
'''