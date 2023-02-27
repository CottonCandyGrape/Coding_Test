#https://school.programmers.co.kr/learn/courses/30/lessons/42583
#DataStructure(Stack,Queue)

def solution(bridge_length, weight, truck_weights):
    b = [0]*bridge_length
    s = 0
    
    count = 0
    while b:
        count += 1
        s -= b.pop(0)
        
        if truck_weights:
            if s+truck_weights[0] <= weight:
                s += truck_weights[0]
                b.append(truck_weights.pop(0))
            else:
                b.append(0) 
    
    return count

#deque는 Queue로 쓰일때만 빠르다.
#stack으로 사용되는 경우는 list 써도 무방.