#https://school.programmers.co.kr/learn/courses/30/lessons/42889
#Sort

def solution(N, stages):
    fails = dict()
    div = len(stages)
    for i in range(1, N+1):
        if div>0:
            cnt = stages.count(i)
            fails[i] = cnt/div
            div -= cnt
        else:
            fails[i] = 0

    sfails = sorted(fails.items(), key=lambda x: (-x[1], x[0]))

    answer = []
    for k,v in sfails:
        answer.append(k)

    return answer