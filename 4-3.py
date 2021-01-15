arr = input()

r = int(arr[1])
c = ord(arr[0]) - ord('a') + 1

count = 0 

steps = [(-1, -2), (1, 2), (-2, -1), (2, 1), (1, -2), (-1, -2), (2, -1), (-2, 1)] 
for step in steps:
    nr = r + step[0]
    nc = c + step[1]
    if nr >= 1 and nc >= 1 and nr <= 8 and nc <= 8:
        count += 1

print(count)