n, m = map(int, input().split())
a, b, d = map(int, input().split())

di = [0, 1, 2, 3]
steps = [(-1, 0), (0, 1), (1, 0), (0, -1)]
mat = [[] for i in range(n)]  

for i in range(n):
    mat[i] = list(map(int, input().split()))
mat[a][b] = 2
one, count = 0, 1

while True:
    d = (d-1+n)%len(di)
    na = a + steps[d][0]
    nb = b + steps[d][1]

    if mat[na][nb] == 0:
        mat[na][nb] = 2
        a, b = na, nb
        count += 1
        one = 0
        continue
    else:
        one += 1
    
    if one == 4:
        break
        na = a - steps[d][0]
        nb = b - steps[d][1]
        if mat[na][nb] == 0 or mat[na][nb] == 2:
            a, b = na, nb
        else:
            break
        one = 0

print(count)

for i in range(n):
    for j in range(m):
        print(mat[i][j], end=' ')
    print()
#--------------------------------------------------------------

# n, m = map(int, input().split())

# d = [[0]*m for _ in range(n)]
# x, y, direction = map(int, input().split())
# d[x][y] = 1

# array = []
# for i in range(n):
#     array.append(list(map(int, input().split())))

# dx = [-1, 0, 1, 0]
# dy = [0, 1, 0, -1]

# def turn_left():
#     global direction
#     direction -= 1
#     if direction == -1:
#         direction = 3

# count = 1
# turn_time = 0
# while True:
#     turn_left()
#     nx = x + dx[direction]
#     ny = y + dy[direction]

#     if d[nx][ny] == 0 and array[nx][ny] == 0:
#         d[nx][ny] = 1
#         x, y = nx, ny
#         count += 1
#         turn_time = 0
#         continue
#     else: turn_time += 1

#     if turn_time == 4:
#         nx = x - dx[direction]
#         ny = y - dy[direction]

#         if array[nx][ny] == 0:
#             x, y = nx, ny
#         else: break
#         turn_time = 0

# print(count)
# for i in range(n):
#     for j in range(m):
#         print(d[i][j], end=' ')
#     print()