#https://www.acmicpc.net/problem/18310
#Sort, Greedy

n = int(input())
h = list(map(int, input().split()))
h.sort()

print(h[(n-1)//2])

# 너무 어렵게 생각했다... 그냥 중간집에서 설치하면 가장 최소가 되는건데...