n = int(input())
n = 1000-n
count = 0

ex = [500, 100, 50, 10, 5, 1]

for i in ex:
    count += n // i
    n %= i

print(count)