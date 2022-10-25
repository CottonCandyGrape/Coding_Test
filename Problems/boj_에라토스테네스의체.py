#https://www.acmicpc.net/problem/2960
#Implementation

n, k = map(int, input().split())

def era(k):
    era = [True for _ in range(n+1)]
    for i in range(2, n+1):
        for j in range(i, n+1, i):
            if era[j]:
                era[j] = False
                k-=1
                if k==0:
                    print(j)
                    return
era(k)