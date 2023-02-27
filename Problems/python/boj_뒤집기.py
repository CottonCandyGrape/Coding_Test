#https://www.acmicpc.net/problem/1439
#Greedy

S = input()

count = 0
for i in range(len(S)-1):
    if S[i] != S[i+1]:
        count += 1
print((count+1)//2)

'''
처음엔 연속되는 0과 1의 개수를 구해야겠다고 생각했다.
근데 그럴필요 없었고 바뀌는 횟수만 카운트 하면 된다.
00011100 을 010으로 봐도 무방하다는 뜻.
string -> count -> answer
0 -> 0-> 0
01 -> 1-> 1
010 -> 2-> 1
0101 -> 3-> 2
01010 -> 4-> 2
010101 -> 5-> 3
'''