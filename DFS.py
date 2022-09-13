def dfs(graph, v, visited):
    visited[v] = True
    print(v, end=' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

def dfs_stk(graph, v, visited): #stack으로 구현한 것인데... 좋아보이지 않는다..
    stk = [v]
    while stk:
        cv = stk.pop()
        if not visited[cv]:
            visited[cv] = True
            print(cv, end=' ')
        for i in range(len(graph[cv])-1, -1, -1):
            if not visited[graph[cv][i]]:
                stk.append(graph[cv][i])

# 방문 기준 : 번호가 낮은 인접 노드 부터 방문한다고 가정.
# 따라서 graph 각 행의 원소를 오름차순으로 초기화.
graph = [
    [],
    [2, 3, 8],
    [1, 7],
    [1, 4, 5],
    [3, 5],
    [3, 4],
    [7],
    [2, 6, 8],
    [1, 7]
]

visited = [False]*9

dfs(graph, 1, visited)