#https://www.acmicpc.net/problem/2504
#Implementation, stack

bracket = list(input())

stack = []
answer = 0
tmp = 1

for i in range(len(bracket)):
    if bracket[i] == "(":
        stack.append(bracket[i])
        tmp *= 2
    elif bracket[i] == "[":
        stack.append(bracket[i])
        tmp *= 3
    elif bracket[i] == ")":
        if not stack or stack[-1] == "[":
            answer = 0
            break
        if bracket[i-1] == "(":
            answer += tmp
        stack.pop()
        tmp //= 2
    else:
        if not stack or stack[-1] == "(":
            answer = 0
            break
        if bracket[i-1] == "[":
            answer += tmp
        stack.pop()
        tmp //= 3

if stack:
    print(0)
else:
    print(answer)

'''
괄호짝 맞추기 문제는 stack을 이용하여 풀어보자.
열린 괄호가 나올때 
1. tmp에 2 or 3을 곱해준다.
닫힌 괄호가 나올때 
1. 직전의 괄호와 비교하여 짝이 맞다면 answer에 더해주고 아니라면 그냥 넘어간다.
2. tmp를 2 or 3으로 나눈다.
3. stack.pop() 해준다.
'''