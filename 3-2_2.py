n, m, k = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort()
first = arr[n-1]
second = arr[n-2]

count = (m//(k+1))*k + m%(k+1)

result = 0
result += count * first
result += (m-count) * second

print(result)