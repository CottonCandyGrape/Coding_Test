#https://www.acmicpc.net/problem/11501
#Greedy

t = int(input())

for i in range(t):
    n = int(input())
    stocks = list(map(int, input().split()))
    maxp = stocks[-1]

    result = 0
    for i in range(n-2, -1, -1):
        if stocks[i]>maxp:
            maxp = stocks[i]
        else:
            result += maxp-stocks[i]
    print(result)

#왜 이런 생각을 못할까...