#https://www.acmicpc.net/problem/1072
#Binary Search, Parametric Search

x, y = map(int, input().split())

z = y*100 // x #int로 씌우는 것보다 정확

result = 0
if z>=99:
    print(-1)
else:
    s = 1
    e = int(1e9)
    while s<=e:
        mid = (s+e) // 2
        newz = (y+mid) * 100 // (x+mid)
        if newz != z: # 계속 이기기만 하니깐 newz>z일 것이다.
            result = mid # 정답인 조건에서의 mid를 답으로 지정
            e = mid-1
        else:
            s = mid + 1
    print(result)