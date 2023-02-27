#https://www.acmicpc.net/problem/17413
#implementation

s = list(input()) #str은 부분 수정 불가능 하므로 list로 바꿔서 사용
s.append(' ') #마지막 idx 사용하고 싶으면 적절한 요소 추가

tag = False
tmp = []

for idx, i in enumerate(s):
    if i=='<' or idx==len(s)-1:
        tag = True

        if tmp: #tmp에 내용이 있으면
            tmp = ''.join(tmp).split()
            ptmp = ''
            for j in tmp:
                ptmp += j[::-1] + ' ' #뒤집어서
            s[idx-len(ptmp)+1:idx] = ptmp[:-1] #s에 저장
            tmp = []

    elif i == '>':
        tag = False
        continue #그대로 넘어가면 tmp에 '>'도 저장됨.

    if not tag: #뒤집어야할 것만 tmp에 저장
        tmp.append(i)

print(''.join(s)) #list인 s를 str로 출력