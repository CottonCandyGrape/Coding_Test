#https://www.acmicpc.net/problem/1475
#Implemetation

from collections import defaultdict

n = list(map(int, input()))

dic = defaultdict(int)
for i in n:
    if i==6:
        dic[9]+=1
    else:
        dic[i] += 1

if max(dic)==9:
    dic[9] = dic[9]//2 if dic[9]%2==0 else dic[9]//2 + 1

print(max(dic.values()))