#https://school.programmers.co.kr/learn/courses/30/lessons/17679
#Implementation

def solution(m, n, board):
    answer = 0
    for i in range(len(board)):
        board[i] = list(board[i]) #string은 list 씌우면 문자 하나씩 떨어진다.
        
    while True:
        poplist = []
        for i in range(m-1):
            for j in range(n-1):
                if board[i][j] == 0:
                    continue
                elif board[i][j] == board[i+1][j] == board[i][j+1] == board[i+1][j+1] != 0:
                    poplist.extend([(i,j), (i+1,j), (i,j+1), (i+1,j+1)]) #list안의 tuple들을 각각 원소로 추가

        poplist = list(set(poplist)) # 중복체크
        if len(poplist) == 0: # 터질게 없으면 중단
            break
            
        answer += len(poplist)
        for x, y in poplist:
            board[x][y] = 0
    	
        for j in range(n):
            for i in range(m-1, -1, -1):
                if board[i][j] == 0:
                    x = i-1
                    while x>-1 and board[x][j]==0:
                        x -= 1

                    if x>=0:
                        board[i][j], board[x][j] = board[x][j], 0 #맞교환이 아니더라도 파이썬은 이렇게 쓸 수 있지!!
    return answer