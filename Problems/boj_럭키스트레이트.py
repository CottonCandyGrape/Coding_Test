#https://www.acmicpc.net/problem/18406
#Implementation

n = input()
mid = len(n)//2
left = sum(list(map(int, n[:mid])))
right = sum(list(map(int, n[mid:])))

if left==right:
    print('LUCKY')
else:
    print('READY')