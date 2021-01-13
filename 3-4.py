n, k = map(int, input().split())

count = 0

while True:
    temp = n % k
    count += temp
    n -= temp

    if n < k: break
    n //= k
    count += 1
count += n - 1

print(count)