def diffusion(room,R,C):
    difdust = [[0 for i in range(C)] for j in range(R)]
    for i in range(R):
        for j in range(C):
            diffu = 0
            if room[i][j] < 5:
                continue
            diffu = room[i][j] // 5
            room[i][j] = room[i][j] - (diffu*4)
           
            for z in range(4):
                if z == 0:
                    if i == 0:
                        room[i][j] += diffu
                    elif (room[i-1][j] == -1):
                        room[i][j] += diffu
                    else:
                        difdust[i-1][j] += diffu
                if z == 1:
                    if j == C-1:
                        room[i][j] += diffu
                    elif room[i][j+1] == -1:
                        room[i][j] += diffu
                    else:
                        difdust[i][j+1] += diffu
                if z == 2:
                    if i == R-1:
                        room[i][j] += diffu
                    elif room[i+1][j] == -1:
                        room[i][j] += diffu
                    else:
                        difdust[i+1][j] += diffu
                if z == 3:
                    if j == 0:
                        room[i][j] += diffu
                    elif (room[i][j-1] == -1):
                        room[i][j] += diffu
                    else:
                        difdust[i][j-1] += diffu 
    for i in range(R):
        for j in range(C):
            room[i][j] += difdust[i][j]
    return room

def move(room,R,C,where):
    #print(where)
    i = where[0]
    
    j = 1
    flag = 0
    nex = room[i][j]
    room[i][j] = 0
    #print(room)
    while True:
        #print("i,j=",i,j)
        #print(room)
        if flag == 0:
            if j == C-2:
                flag += 1
            nex,room[i][j+1] = room[i][j+1], nex
            j += 1
        if flag == 1:
            if i == 1:
                flag += 1
            nex, room[i-1][j] = room[i-1][j],nex
            i -= 1
        if flag == 2:
            if j == 1:
                flag += 1
            nex,room[i][j-1] = room[i][j-1], nex
            j -= 1

        if flag == 3:
            #print("i=",i)
            if room[i+1][j] == -1:
                break
            nex,room[i+1][j] = room[i+1][j],nex
            i += 1
    
    i = where[1]
    j = 1
    flag = 0
    nex = room[i][j]
    room[i][j] = 0
    while True:
        #print(room)
        #print("i,j=",i,j)
        if flag == 0:
            if j == C-2:
                flag += 1
            nex,room[i][j+1] = room[i][j+1], nex
            j += 1
        if flag == 1:
            if i == R-2:
                flag += 1
            nex, room[i+1][j] = room[i+1][j],nex
            i += 1            
        if flag == 2:
            if j == 1:
                flag += 1
            nex,room[i][j-1] = room[i][j-1], nex
            j -= 1
        if flag == 3:
            if room[i-1][j] == -1:
                break
            nex,room[i-1][j] = room[i-1][j],nex
            i -= 1
        #print(room[3][0])
    #print(room)
    return room

def remain_dust(room):
    result = 0
    for x in room:
        result += sum(x)
    result += 2
    return result

if __name__ == "__main__":
    R, C, T = input().split()
    R = int(R)
    C = int(C)
    T = int(T)
    room = []
    
    for i in range(R):
        temp = input().split()
        temp = list(map(int,temp))
        room.append(temp)
    where = []
    for i in range(R):
        if room[i][0] == -1:
            where.append(i)
    for i in range(T):
        #print(i)
        room = diffusion(room,R,C)
        room = move(room,R,C,where)
    print(remain_dust(room))