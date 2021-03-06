

def t_init(inp ,tree, node, start, end):
    if start == end:
        tree[node] = inp[start]
        return tree[node]
    else:
        tree[node] = t_init(inp, tree, node*2, start, (start+end)//2) + t_init(inp, tree, node*2+1,(start+end)//2+1, end)
        return tree[node]

def t_sum(tree, node, start, end, left, right):
    if (left > end) or (right < start):
        return 0
    if (left <= start) and (end <= right):
        return tree[node]
    return t_sum(tree, node*2, start, (start+end)//2, left, right) + t_sum(tree, node*2+1, (start+end)//2+1, end, left, right)

def t_update(tree, node, start, end, index, diff):
    if (index < start) or (index > end):
        return 0
    tree[node] = tree[node] + diff
    if start != end:
        t_update(tree, node * 2, start, (start+end)//2, index, diff)
        t_update(tree, node * 2 + 1, (start+end)//2 + 1,end, index, diff)

if __name__ == "__main__":
    N, M, K = input().split()
    N = int(N)
    M = int(M)
    K = int(K)
    inp = list()
    for i in range(N):
        temp = input()
        temp = int(temp)
        inp.append(temp)
    tree = [0 for i in range(N * 8)]
    t_init(inp,tree,1,0,N-1)
    print(tree)
    for i in range(M+K):
        a,b,c = input().split()
        a = int(a)
        b = int(b)
        c = int(c)
        if a == 1:
            diff = c - inp[b-1]
            inp[b-1] = c
            t_update(tree, 1, 0, N-1, b-1, diff)
        if a == 2:
            print(t_sum(tree, 1, 0, N-1, b-1, c-1))
    

