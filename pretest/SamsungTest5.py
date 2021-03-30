import queue
import copy
import numpy as np

visit = list()
count = queue.Queue()

def move(board,q):
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]
    count.put(0)
    #print(visit)
    while not q.empty():
        temp = list()
        temp = q.get()
        cnt = count.get()
        if board[temp[0]][temp[1]] == chr(79):
                return cnt
        for i in range(4):
            ttemp = list()
            ttemp = copy.deepcopy(temp)
            #print(temp)
            print(ttemp[0],ttemp[1])
            while (board[ttemp[0]][ttemp[1]] != chr(79)) and (board[ttemp[0]+dx[i]][ttemp[1]+dy[i]] != '#'):
                if ttemp[0] == 3 and ttemp[1] == 2:
                    print('hi')
                ttemp[0] += dx[i]
                ttemp[1] += dy[i]
            while (board[ttemp[2]+dx[i]][ttemp[3]+dy[i]] != '#') and (board[ttemp[2]][ttemp[3]] != chr(79)):
                ttemp[2] += dx[i]
                ttemp[3] += dy[i]
            #print("1:",ttemp)
            if ttemp[0]  == ttemp[2] and ttemp[1] == ttemp[3]:
                if board[ttemp[0]][ttemp[1]] == chr(79):   
                    continue
                if abs(ttemp[0]-temp[0]) + abs(ttemp[1]-temp[1]) > abs(ttemp[2] - temp[2]) + abs(ttemp[3] - temp[3]):
                    ttemp[0] = ttemp[0] - dx[i]
                    ttemp[1] = ttemp[1] - dy[i]
                else:
                    ttemp[3] = ttemp[3] - dy[i]
                    ttemp[2] = ttemp[2] - dx[i]
            #print("2:",ttemp)
            #print(visit)
            if ttemp not in visit:
                #print('hi')
                q.put(ttemp)
                count.put(cnt+1)
                visit.append(ttemp)

            
    return -1

if __name__ == "__main__":
    a,b = input().split()
    a = int(a)
    b = int(b)
    board = list()
    q = queue.Queue()
    tttemp = list()
    for i in range(a):
        ttemp = input()
        temp = list()
        for j in range(b):
            if ttemp[j] == 'R':
                tttemp.append(i)
                tttemp.append(j)
            elif ttemp[j] == 'B':
                tttemp.append(i)
                tttemp.append(j)
            temp.append(ttemp[j])
        board.append(temp)
    visit.append(copy.deepcopy(tttemp))
    q.put(tttemp)
    print(move(board,q))
