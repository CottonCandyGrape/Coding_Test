#https://www.acmicpc.net/problem/14888
#DFS

n = int(input())
nums = list(map(int, input().split()))
op = list(map(int, input().split()))

minv = int(1e9) 
maxv = -int(1e9) 

def dfs(i, now, add, sub, mul, div):
    global minv, maxv
    if i==n:
        minv = min(now, minv)
        maxv = max(now, maxv)
        return
        
    if add:
        dfs(i+1, now+nums[i], add-1, sub, mul, div)
    if sub:
        dfs(i+1, now-nums[i], add, sub-1, mul, div)
    if mul:
        dfs(i+1, now*nums[i], add, sub, mul-1, div)
    if div:
        dfs(i+1, int(now/nums[i]), add, sub, mul, div-1)
        #음수를 나눌때는 //, %의 결과가 다르다

dfs(1, nums[0], op[0], op[1], op[2], op[3])

print(maxv)
print(minv)