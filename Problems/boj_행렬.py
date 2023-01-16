#https://www.acmicpc.net/problem/1080
#Greedy

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
A = [list(map(int, input().rstrip())) for _ in range(n)]
B = [list(map(int, input().rstrip())) for _ in range(n)]

fc = 3
rc = n-fc+1
cc = m-fc+1

def flip(x, y):
    for i in range(x, x+fc):
        for j in range(y, y+fc):
            A[i][j] = 1-A[i][j] #good sense

result = 0
for i in range(rc):
    for j in range(cc):
        if A[i][j]!=B[i][j]:
            result += 1
            flip(i, j)
        if A==B:
            break
    if A==B:
        break
        
if A==B:
    print(result)
else:
    print(-1)

'''
A==B로 비교가 되는구나...
[i][j]로 하나씩 비교하면서 다르면 뒤집는다. 
그러면 필터가 닿는 곳까지는 같게 만들 수 있다. 
필터가 닿지 않는 곳은 고려하지 않고 다르다면 -1 출력하면 된다.
'''    