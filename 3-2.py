n, m, k = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort()
first = arr[n-1]
second = arr[n-2]

result = 0

while True:
    if m == 0:break
    result += first*k
    m -= 3
    if m == 0:break
    result += second
    m -=1
    
print(result)