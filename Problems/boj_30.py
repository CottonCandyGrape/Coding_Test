#https://www.acmicpc.net/problem/10610
#Greedy

n = list(map(int, input()))
n.sort(reverse=True)
if n[-1]==0 and sum(n)%3==0:
    for i in n:
        print(i, end='')
else:
    print(-1)