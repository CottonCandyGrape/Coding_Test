#https://www.acmicpc.net/problem/15904
#Greedy

# 1번 방법
s = list(input().replace(' ',''))

idx = 0
ucpc = 'UCPC'
for i in s: #모든 s 확인
    if i == ucpc[idx]:
        idx += 1
    if idx == 4:
        print('I love UCPC')
        break
      
else:
    print('I hate UCPC')

# 2번 방법
s = list(input())

idx = 0
ucpc = 'UCPC'
for i in ucpc:
    if i in s:
        idx += 1
        s = s[s.index(i)+1:] # s 재할당
    else:
        print('I hate UCPC')
        break
else:
    if idx == 4:
        print('I love UCPC')