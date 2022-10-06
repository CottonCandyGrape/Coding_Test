#https://school.programmers.co.kr/learn/courses/30/lessons/42746
#Sorting

def solution(numbers):
    answer = ''
    numbers = list(map(str, numbers))
    numbers.sort(key=lambda x: x*3, reverse=True)
    answer = str(int(''.join(numbers)))
    
    return answer

'''
원소가 1000이하 이므로 str로 치환 후 3번 반복하여 비교한다.
3   | 333
31  | 313131
310 | 310310310
현재 비교하는 자리수의 숫자가 같다면 뒷자리를 비교해야 하는데
자리수가 모자라면 그대로 그 자리수의 수를 사용해야한다.

별로 와닿는 풀이는 아닌데 이해는 했다...
'''