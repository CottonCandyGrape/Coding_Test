#https://www.acmicpc.net/problem/1969
#Greedy, Implementation, Brute Force

from collections import defaultdict
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
dna = [input().rstrip() for _ in range(n)]

result = ''
count = 0

for d in zip(*dna):
    tmp = defaultdict(int)
    for c in d:
        tmp[c] += 1
        
    stmp = sorted(tmp.items(), key=lambda x: (-x[1],x[0]))
    result += stmp[0][0]
    del tmp[result[-1]]
    
    count += sum(tmp.values())

print(result)
print(count)