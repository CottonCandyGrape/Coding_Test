#https://www.acmicpc.net/problem/1213
#Implementation, Greedy

from collections import defaultdict 

s = list(input())
s.sort()

d = defaultdict(int)
for i in s:
    d[i] += 1

c = []
cnt = 0
for key, val in d.items():
    if val%2 != 0:
        cnt += 1
        c.append(key)
        s.remove(key)

    if cnt > 1:
        print("I'm Sorry Hansoo")
        break
else:
    l = []
    for i in range(0, len(s), 2):
        l.append(s[i])

    result = l+c+l[::-1]
    print(''.join(result))

#Counter 사용#
from collections import Counter 

s = list(input())
s.sort()

counter = Counter(s)

c = []
cnt = 0
for i in counter:
    if counter[i]%2!=0:
        cnt += 1
        c.append(i)
        s.remove(i)

    if cnt > 1:
        print("I'm Sorry Hansoo")
        break
else:
    l = []
    for i in range(0, len(s), 2):
        l.append(s[i])

    result = l+c+l[::-1]
    print(''.join(result))
    