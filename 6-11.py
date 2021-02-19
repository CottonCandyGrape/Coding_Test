n = int(input())

arr = []
for i in range(n):
    score = input().split()
    arr.append((score[0], score[1]))

arr.sort(key=lambda name: name[1])

for i in arr:
    print(i[0], end=' ')