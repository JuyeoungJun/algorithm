import itertools

N = int(input())
play = list()
player = [1,2,3,4,5,6,7,8]
for i in range(N):
    temp = input().split()
    temp = list(map(int, temp))
    play.append(temp)
maxx = 0
playorder = map(list,itertools.permutations(player))
for x in playorder:
    x.insert(3,0)
    order = 0
    score = 0
    outcount = 0
    base = [0] * 3
    out = 0
    while out < N:
        if outcount == 3:
            out += 1
            outcount = 0
            continue
        flag = 0
        if play[out][x[order]] == 0:
            outcount += 1
            order = (order + 1)%9
        else:
            base.append(1)
            for i in range(play[out][x[order]]):
                score += base.pop(0)
            for i in range(3-len(base)):
                base.append(0)
            order = (order + 1) % 9
    maxx = max(score,maxx)
print(maxx)




        