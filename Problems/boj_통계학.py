#https://www.acmicpc.net/problem/2108
#Implemetation

from collections import defaultdict
import sys

input = sys.stdin.readline #입력은 무조건 이걸로 받자... 시간초과 ㅂㄷㅂㄷ..
n = int(input())
nums = [int(input()) for _ in range(n)] 

print(round(sum(nums)/n))

mid = n//2
print(sorted(nums)[mid])

dic = defaultdict(int)
for i in nums:
    dic[i] += 1

maxcnt = max(dic.values())
frq = []
for key, value in dic.items():
    if maxcnt == value:
        frq.append(key)
if len(frq)>1:
    frq.sort()
    print(frq[1])
else:
    print(frq[0])

print(max(nums)-min(nums))


#Counter를 이용한 풀
from collections import Counter

n = int(input())
nums = [int(input()) for _ in range(n)]

print(round(sum(nums) / n))

mid = n // 2
print(sorted(nums)[mid])

counter = Counter(sorted(nums)).most_common()
if len(counter)>1:
    if counter[0][1]==counter[1][1]:
        print(counter[1][0])
    else:
        print(counter[0][0])
else:
    print(counter[0][0])

print(max(nums) - min(nums))
