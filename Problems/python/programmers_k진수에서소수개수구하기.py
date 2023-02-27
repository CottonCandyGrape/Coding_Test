#https://school.programmers.co.kr/learn/courses/30/lessons/92335

def prime(n):
    if n<=1:
        return False
    for i in range(2,int(n**0.5)+1):
        if n%i == 0:
            return False
    return True
    
def solution(n, k):
    kn = ''
    while n>0:
        kn += str(n%k)
        n //= k
    
    kn = kn[::-1]
    kn = kn.replace('0', ' ')
    plist = list(map(int, kn.split()))
    
    answer = 0
    for i in plist:
        print(i)
        if prime(i):
            answer += 1
        
    return answer