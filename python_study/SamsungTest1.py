#def dfs(graph, start, goal):
def dfs_paths(graph, start, goal):
    st = []
    st = st+graph[start]
    visit = []
    while st:
        a = st.pop()
        if a == goal:
            return 1
        if a not in visit:
            visit.append(a)
            st.extend(graph[a])
    return 0

def bfs(graph, start_node):
    visit = list()
    queue = list()

    queue.append(start_node)

    while queue:
        node = queue.pop(0)
        if node not in visit:
            visit.append(node)
            queue.extend(graph[node])

    return visit

def dfs(graph, start_node):
    visit = list()
    stack = list()

    stack.append(start_node)

    while stack:
        node = stack.pop()
        if node not in visit:
            visit.append(node)
            stack.extend(graph[node])

    return visit    

if __name__ == "__main__":
    n = int(input())
    mapp = dict()
    for i in range(n):
        mapp[i] = list()
        flag = 0
        temp = input()
        temp = temp.split()
        temp = list(map(int,temp))
        for j in range(len(temp)):
            if temp[j] == 1:
               
                mapp[i].append(j)
        flag = 0
    #print(mapp)
    for i in range(n):
        for j in range(n):
            if dfs_paths(mapp, i, j) == 1:
                print("1 ",end = '')
            else:
                print("0 ", end= '')
        print('\n',end = '')


