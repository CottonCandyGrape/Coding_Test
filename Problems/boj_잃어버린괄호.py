#https://www.acmicpc.net/problem/1541
#Greedy

s = input()

s = s.split('-')
total = sum(list(map(int, s[0].split('+'))))

for i in range(1, len(s)):
    total -= sum(list(map(int, s[i].split('+'))))
print(total)