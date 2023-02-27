#최대공약수(for)
def GCD_for(a, b):
    for i in range(min(a,b), 0, -1):
        if a%i==0 and b%i==0:
            return i
            
#최소공배수(for)
def LCM_for(a, b):
    for i in range(max(a,b), (a*b)+1):
        if i%a==0 and i%b==0:
            return i
            
#최대공약수(유클리드 호제법)
def GCD(a, b):
    while(b):
        a, b = b, a%b
    return a
    
#최소공배수
def LCM(a, b):
    return (a*b) // GCD(a, b)