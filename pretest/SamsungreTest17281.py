import itertools

N = int(input())
play = list()
player = [1,2,3,4,5,6,7,8]
for i in range(N):
    temp = input().split()
    temp = list(map(int, temp))
    play.append(temp)
maxx = 0
#playorder = map(list,itertools.permutations(player))
for x in play:
    temp = x.pop(0)
    order = set(itertools.permutations(x))
    order = map(list,order)
    for i in order:
        i.insert(3,temp)




        