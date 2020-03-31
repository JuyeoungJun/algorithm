
def bfs(Freind,start,end):
    stack = [start]
    count = [0]
    visit = []
    while stack:
        #print("st=",stack,"count=",count)
        temp = stack.pop(0)
        ctemp = count.pop(0)
        if temp == end:
            return ctemp
        if temp not in visit:
            visit.append(temp)
            stack.extend(Freind[temp])
            n = len(Freind[temp])
            for i in range(n):
                count.append(ctemp+1)
        
    return 0

if __name__ == "__main__":
    N, M = input().split()
    N = int(N)
    M = int(M)
    Friend = dict()
    for i in range(M):
        a,b = input().split()
        a = int(a)
        b = int(b)
        if a not in Friend.keys():
            Friend[a] = set()
        if b not in Friend.keys():
            Friend[b] = set()
        Friend[a].add(b)
        Friend[b].add(a)
    min = 987654321
    minnum = 0
    for i in range(1,N+1):
        sum = 0
        for j in range(1,N+1):
            sum = sum + bfs(Friend,i,j)
        if sum < min:
            min = sum
            minnum = i
    print(minnum)