#https://www.acmicpc.net/problem/1049
#Greedy

n, m = map(int, input().split())
pm, nm = 1001, 1001

for i in range(m):
    a, b = map(int, input().split())
    pm = min(pm, a)
    nm = min(nm, b)

result = 0

if 6*nm < pm:
    result = n*nm
else:
    pn = n//6
    nn = n%6
    if nn * nm > pm:
        nn = 0
        pn += 1 
        
    result = pn*pm+nn*nm 
print(result)