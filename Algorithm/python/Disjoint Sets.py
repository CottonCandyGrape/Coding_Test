# 특정 원소가 속한 집합 찾기
def find_parent(parent, x):
    # 루트 노드를 찾을 때까지 재귀 호출 
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x]) #경로 압축법
        #return find_parent(parent, parent[x])
    return parent[x] #경로 압축법
    #return x

# 두 원소가 속한 집합을 합치기
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b

# 노드의 개수와 간선(Union 연산)의 개수 입력 받기
v, e = map(int, input().split())
parent = [0] * (v+1) # 부모 테이블 초기화하기

# 부모 테이블상에서, 부모를 자기 자신으로 초기화
for i in range(1, v+1):
    parent[i] = i

# 서로소 집합 자료구조 구현 -> Union 연산을 각각 수행
for i in range(e):
    a, b = map(int, input().split())
    union_parent(parent, a, b, end=' ')
# --------------------------
    
# 사이클 판별하는 방법 ---------
cycle = False

for i in range(e):
    a, b = map(int, input().split())
    # 사이클이 발생한 경우=루트가 같은 경우
    if find_parent(parent, a) == find_parent(parent, b):
        cycle = True
        break
    # 사이클이 발생하지 않았다면 합치기 연산 수행
    else:
        union_parent(parent, a, b)
# ---------------------------        
        
# 각 원소가 속한 집합 출력하기
for i in range(1, v+1):
    print(find_parent(parent, i))

# 부모 테이블 내용 출력
for i in range(1, v+1):
    print(parent[i], end=' ')