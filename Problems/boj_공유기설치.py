#https://www.acmicpc.net/problem/2110
#Binary Search, Parametric Search

n, c = map(int, input().split())
hlist = [int(input()) for _ in range(n)]
hlist.sort()

start = 1 # 최소 거리 : 배열의 첫번째 원소가 아닌 1
end = hlist[-1] - hlist[0] # 최대 거리 : 제일 작은 원소와 큰 원소의 차이
result = 0

while start<=end:
    mid = (start+end) // 2
    val = hlist[0]
    count = 1
    for i in range(1, n):
        if hlist[i] >= mid+val:
            val = hlist[i]
            count += 1
    if count >= c: # c개 이상이면 거리를 증가
        start = mid + 1
        result = mid
    else:
        end = mid - 1
        
print(result)

'''
백준에서 python으로 하면 시간 초과남.ㅡㅡ
첨부터 공유기 개수를 c개로 하고 hlist 에서 c개만큼 뽑는 조합의 방법을 생각했다.
역시나 비효율적이어서 틀림.
간격을 조절하면서 공유기 개수를 count 하는게 관건이었음.
이진 탐색을 어떻게 적용해야 하는지가 중요하다.
이건 문제를 많이 풀어봐야겠다.
'''