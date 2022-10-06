#https://www.acmicpc.net/problem/2512
#Binary Search, Parametric Search

n = int(input())
b = list(map(int, input().split()))
m = int(input())

minb = 0 #이걸 min(b)가 아니라 0으로 두는 것.(예산이 너무 적을 경우)
maxb = max(b) 

result = 0
while minb<=maxb:
    sumb = 0
    mid = (minb+maxb) // 2
    for i in b:
        if mid<i:
            sumb += mid
        else:
            sumb += i

    if sumb > m:
        maxb = mid - 1
    else:
        result = mid # 정답인 조건에서의 mid를 답으로 지정
        minb = mid + 1
print(result)