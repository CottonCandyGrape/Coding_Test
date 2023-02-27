#https://www.acmicpc.net/problem/16953
#Greedy

a, b = map(int, input().split())
count = 0
while True:
    tmp = b
    if b%10==1:
        b = b//10
    elif b%2==0:
        b = b//2
        
    count += 1
    
    if b==a:
        print(count+1)
        break
    elif tmp==b:
        #끝에 1이 아니거나 홀수이면(=b가 변하지 않는다면)
        #답을 도출할수없음.
        print(-1)
        break