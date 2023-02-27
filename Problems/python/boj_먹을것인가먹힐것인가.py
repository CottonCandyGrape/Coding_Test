#https://www.acmicpc.net/problem/7795
#Binary Search

import bisect
import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    
    a.sort()
    b.sort()

    count = 0
    for i in a:
        count += bisect.bisect(b, i-1)
        #count += bisect.bisect_left(b, i) #위와 같은 결과
    '''
    for i in a:
        s = 0
        e = m-1
        idx = 0
        while s<=e:
            mid = (s+e)//2
            if i>b[mid]:
                idx = mid+1
                s = mid+1
            else:
                e = mid-1
        if idx>0:
            count += idx
    '''
                
    print(count)

'''
a.sort(reverse=True), b.sort() 후 
2중 for문 써서 a의 원소 i가 b의 첫번째 원소보다 클때 
2번째 for문에서 i 보다 큰 개수를 count에 추가했었다.
근데 시간초과 남. 

결론 : while로 이분탐색하는게 훨씬 빠르다
최종 결론 : 근데 bisect 쓰는게 더 간단
'''