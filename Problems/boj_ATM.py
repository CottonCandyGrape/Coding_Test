#https://www.acmicpc.net/problem/11399
#Greedy, Sort

n = int(input())
l = list(map(int, input().split())) 
l.sort()

time = [0] 

for i in range(n):
    time.append(time[i]+l[i])
print(sum(time))