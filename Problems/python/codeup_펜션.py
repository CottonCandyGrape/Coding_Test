#https://codeup.kr/problem.php?id=4040
#Greedy

n, m = map(int, input().split())
    
reserve = [input() for _ in range(n)]
s, e = map(int, input().split())
s -= 1
e -= 1

def check(k): #빈방의 인덱스 고려 x. 단지 그날 최대로 묵을수있는 일수를 계산.
    mday = 0
    for i in range(m):
        day = 0
        for j in range(k, e):
            if reserve[j][i]=='O':
                day += 1
            else:
                break
        mday = max(mday, day)
    return mday

count = -1 
today = s
while today<e:
    ct = check(today)
    if ct == 0:
        count = -1
        break

    count += 1
    today += ct
    
print(count)