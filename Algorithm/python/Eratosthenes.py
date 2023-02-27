def eratosthenes(n):
    era = [True for _ in range(n+1)]
    era[0], era[1] = False, False
    primes = [] #prime 배열 안쓴다면 생략 가능
    for i in range(2, int(n**0.5)+1): # 제곱근까지만 봐도 무방! 단, prime 배열 쓴다면 n+1 까지
        if era[i]:
            primes.append(i) #prime 배열 안쓴다면 생략 가능
            for j in range(i*2, n+1, i):
                era[j] = False
    return era, primes # 둘 중 필요한 것 골라 쓰면 된다.

#소수 판별 함수
def isPrime(n):
    if n<=1:
        return False
    for i in range(2, int(n**0.5)+1):
        if n%i==0:
            return False
    return True

