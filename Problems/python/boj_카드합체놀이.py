#https://www.acmicpc.net/problem/15903
#Greedy

n, m = map(int, input().split())
l = list(map(int, input().split()))
for i in range(m):
    l.sort()
    l[0], l[1] = l[0]+l[1], l[0]+l[1]
            
print(sum(l))

#생각해냈다 ㅠ