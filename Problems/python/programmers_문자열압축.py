#https://school.programmers.co.kr/learn/courses/30/lessons/60057
#Implmentation

# 내가 짠거 (+나랑 비슷했던 사람꺼)
def solution(s):
    answer = len(s) 
    for i in range(1, (len(s)//2)+1):
        count = 1
        string = ''
        for j in range(0, len(s), i):
            if s[j:j+i] == s[j+i:j+2*i]:
                count += 1
            else:
                if count > 1:
                    string += str(count)
                string += s[j:j+i]
                count = 1
        
        answer = min(answer, len(string)) 
                 
    return answer

# 잘 짠 사람

def compress(text, tok_len):
    # 길이 별로 나누는 작업 list랑 for이용해서 잘했다.
    words = [text[i:i+tok_len] for i in range(0, len(text), tok_len)]
    res = []
    cur_word = words[0]
    cur_cnt = 1
    # i, i+1 번째 단어 비교하는 부분인데 하나 밀고 뒤에 공백 채워서 zip 활용한거 쩔었다.
    for a, b in zip(words, words[1:] + ['']):
        if a == b:
            cur_cnt += 1
        else:
            res.append([cur_word, cur_cnt])
            cur_word = b
            cur_cnt = 1
    #결론적으로 string이 어떻게 생겼는지 보다 길이가 중요하니 길이값으로 리턴하는거 잘했다.
    return sum(len(word) + (len(str(cnt)) if cnt > 1 else 0) for word, cnt in res)

def solution(text):
    return min(compress(text, tok_len) for tok_len in list(range(1, int(len(text)/2) + 1)) + [len(text)])
