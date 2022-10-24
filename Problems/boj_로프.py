#https://www.acmicpc.net/problem/2217
#Greedy, Sort

k = int(input())
w = [int(input()) for i in range(k)]
w.sort(reverse=True)

mw = [] 
for i in range(k):
    mw.append((i+1)*w[i])

mw.sort()
print(mw[-1])

'''
x>y 일때 x*k<y*(k+1) 이 가능.
따라서 mw는 끝까지 다 구한후 최대값 찾음.
'''