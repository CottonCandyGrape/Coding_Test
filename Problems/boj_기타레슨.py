#https://www.acmicpc.net/problem/2343
#Binary Search

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
l = list(map(int, input().split()))

#2번째 풀이
s = max(l) #여기서 헤맸다...
e = n*int(1e4)

result = 0
while s<=e:
    mid = (s+e)//2

    count = 1
    tmp = 0
    for i in l:
        tmp += i
        if tmp>mid:
            count += 1
            tmp = i

    if count>m:
        s = mid+1
    else:
        result = mid
        e = mid-1

print(result)


'''
result = int(1e9) #최솟값 구하는거니 첨엔 큰 값
start = max(l) #크기가 max(l)이 되어야 어떤 강의라도 1개는 들어갈 수 있다.
end  = sum(l)

while start<=end:
    count = 1 # for문에서 마지막 블루레이에 담길 카운트를 고려하여 1로 설정
    mid = (start+end)//2 #블루레이의 크기

    val = 0
    for i in range(n):
        if val+l[i] <= mid:
            val += l[i]
        else:
            count += 1
            val = l[i]

    if count <= m:
        end = mid-1
        result = min(result, mid) #배열에 append해서 min값 찾는거 보다 나음
    else:
        start = mid+1
    
print(result)
'''
'''
이분 탐색 문제인걸 모르고 봤으면 어리둥절했을거다...
근데 알고봤어도 어떻게 적용해야할지 몰랐다.
결국 start, mid, end를 어떻게 결정하느냐가 관건!!!
많이 풀어보자
'''