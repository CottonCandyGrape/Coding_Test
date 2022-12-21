#https://www.acmicpc.net/problem/3085
#Implementation

import sys
input = sys.stdin.readline

n = int(input())
mat = [list(input().rstrip()) for _ in range(n)]
#input 재정의 한거 때문에 rstrip() 써야함. 아니면 \n도 원소로 추가됨

def check(m):
    count = 0
    rlist = [r for r in m]
    clist = [list(c) for c in zip(*m)]
    check = rlist + clist
    for l in check:
        cnt = 1
        for i in range(n-1):
            if l[i] == l[i+1]:
                cnt += 1
            else:
                cnt = 1
            count = max(cnt, count) #이걸 한 인덴트 밖에서 하고 있었다. 그니깐 count 값이 안커진거다...ㅠ
    return count
    
def sol():
    moves = ((1,0),(0,1))
    result = 0

    for x in range(n):
        for y in range(n):
            for move in moves:
                nx = x+move[0]
                ny = y+move[1]
                
                if not 0<=nx<n or not 0<=ny<n:
                    continue
                    
                if mat[x][y] != mat[nx][ny]:
                    mat[x][y], mat[nx][ny] = mat[nx][ny], mat[x][y]
                    result = max(check(mat), result)
                    mat[x][y], mat[nx][ny] = mat[nx][ny], mat[x][y]
    return result

print(sol())