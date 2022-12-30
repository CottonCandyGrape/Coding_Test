#https://school.programmers.co.kr/learn/courses/30/lessons/42587
#Data Structure(Stack, Queue)

from collections import deque

def solution(priorities, location):
    q = deque(priorities)
    mval = max(priorities)
    
    count = 0
    while True:
        val = q[0]
        if val < mval:
            q.rotate(-1)
        else:
            count += 1
            if location == 0:
                return count
            else:
                q.popleft()
                mval = max(q)
                
        location = (location-1+len(q))%len(q)

#any 풀이
'''
def solution(priorities, location):
    queue =  [(i,p) for i,p in enumerate(priorities)]
    answer = 0
    while True:
        cur = queue.pop(0)
        if any(cur[1] < q[1] for q in queue):
            queue.append(cur)
        else:
            answer += 1
            if cur[0] == location:
                return answer
'''