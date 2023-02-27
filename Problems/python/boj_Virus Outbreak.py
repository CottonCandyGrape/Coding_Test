#https://www.acmicpc.net/problem/15841
#DP

hours = []
while True:
    n = int(input())
    if n != -1:
        hours.append(n)
    else:
        break

m = [1]*max(hours)

for i in range(2, len(m)):
    if m[i] == 1:
        m[i] = m[i-1] + m[i-2]

for hour in hours:
    print(f"Hour {hour}: {m[hour-1]} cow(s) affected")