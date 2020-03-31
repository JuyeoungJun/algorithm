

def t_init(arr, tree, node, start, end):
    if start == end:
        tree[node] = arr[start]
        return tree[node]
    else:
        tree[node] = t_init(arr,tree,node*2,start,(start+end)//2) + t_init(arr,tree,node*2+1,(start+end)//2 + 1, end)
        return tree[node]

def t_sum(arr,tree,node,start,end,left,right):
    if start > left or right > end:
        return 0
    if start <= left and right <= end:
        return tree[node]
    return t_sum(arr,tree,node*2,start,(start+end)//2,left,right) + t_sum(arr,tree,node*2+1,(start+end)//2+1,left,right)

def t_update(arr, tree, node, start, end, left, right):
    exit(1)



if __name__ == "__main__":
    N, Q = input().split()
    N = int(N)
    Q = int(Q)
    arr = list(input().split())
    arr = list(map(int,arr))
    print(arr)
    tree = [0 for i in range(N*5)]
    t_init(arr,tree,1,0,N-1)
    print(tree)
    for i in range(Q):
        a,b,c,d = input().split()
        a = int(a)
        b = int(b)
        c = int(c)
        d = int(d)
        t_sum(arr,tree,1,0,N,a,b)
        exit(1)
        t_update(arr,tree,1,0,N,c,d)

    