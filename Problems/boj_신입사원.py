#https://www.acmicpc.net/problem/1946
#Greedy

import sys
input = sys.stdin.readline

t = int(input())

for i in range(t):
    n = int(input())
    cand = [tuple(map(int, input().split())) for i in range(n)]
    cand.sort(key=lambda x: x[0]) #서류 점수로 정렬하고

    result = 1
    man = cand[0][1] #서류 1등은 무조건 뽑히므로 기준맨으로 설정
    for j in range(1, n):
        if cand[j][1]<man: 
            man = cand[j][1] #뽑힌애를 기준맨으로 변경(다음에 뽑히려면 얘보다 높아야함)
            result += 1
            
    print(result)

    #서류 성적 높은 애들을 이기려면 면접 성적이 좋아야한다.
    #미리 뽑힌 애들(=서류가 높다는 뜻) 중 가장 높은 면접 성적보다 높아야한다.
    #면접에서 뒤집어야 하기 때문에 더 높은 성적이 필요

    #많이 접해보는수 밖에 없겠다...