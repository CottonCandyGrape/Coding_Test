#https://school.programmers.co.kr/learn/courses/30/lessons/60058
#DFS, Implemetation

def splitUV(uv):
    count = 0
    for i in range(len(uv)):
        if uv[i]=='(':
            count += 1
        else:
            count -= 1
        if count == 0:
            u = uv[:i+1]
            v = uv[i+1:]
            return u, v
            
def isRight(p): #이게 좀 어려웠다.
    count = 0
    for i in p:
        if i=='(':
            count += 1
        else:
            #count가 0인 상황(=균형이 맞는 상황)에서 한번더 ')'가 나와서 올바르지 X
            if count == 0: 
                return False
            count -= 1
    return True
    
def process(string):
    u, v = splitUV(string)
            
    #재귀의 탈출 조건
    if v!="":
        v = process(v)
        
    if isRight(u):
        return u+v
    else:
        tmp = ''
        for i in range(1, len(u)-1):
            if u[i]=='(':
                tmp += ')'
            else:
                tmp += '('

        return '('+v+')' + tmp
    
def solution(p):
    if isRight(p):
        return p
    return process(p)

'''
str type인 tmp는 요소를 수정할 수 없다. 
대체 방법 : str -> list -> str
u = list(u[1:-1])
for i in range(len(u)):
    if u[i] == '(':
        u[i] = ')'
    else:
        u[i] = '('
u = ''.join(u)
'''