#https://school.programmers.co.kr/learn/courses/30/lessons/42891
#Greedy

#정확성만을 위한 코드(정확성은 통과)
def solution(food_times, k):
    idx = 0
    if sum(food_times) <= k: # k가 시간의 합이 크거나 같다면 return -1
        return -1
    
    while k>0: #k초만큼 하나씩 -1
        if food_times[idx]>0:
            food_times[idx] -= 1
            k -= 1
        idx = (idx+1)%len(food_times)

    if food_times[idx]>0: #위 while의 다음 idx가 양수일 경우
        return idx+1
    else:
        count = 0
        while True:
            idx = (idx+1)%len(food_times)
            if food_times[idx] > 0: # 남은 음식이 나올때까지 idx 찾기
                return idx+1
            else:
                count += 1
                if count >= len(food_times)-1: #한바퀴 다 돌고도 먹을 음식이 없다면 return -1
                    return -1