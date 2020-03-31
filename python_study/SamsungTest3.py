import sys


def rcalculate(array, rm, cm):
    
    nu = [0] * 100
    newarray = []
    for i in range(rm+1):
        temp = dict()
        for x in array[i]:
            if x in temp:
                temp[x] += 1
            elif (x not in temp) and (x != 0):
                temp[x] = 1
        dictlist = list()

        for key, value in temp.items():
            ttemp = [key,value]
            dictlist.append(ttemp)
        dictlist = sorted (dictlist, key = lambda x : x[0])
        dictlist = sorted(dictlist, key = lambda x:x[1])
        temp = []
        for x in dictlist:
            temp.append(x[0])
            if len(temp) >= 100:
                break
            temp.append(x[1])
            if len(temp) >= 100:
                break
        if cm < len(temp):
            cm = len(temp)
        for i in range(len(temp),100):
            temp.append(0)
        newarray.append(temp)
    for i in range(rm+1, 100):
        newarray.append(nu)
    return newarray, cm

if __name__ == "__main__":
    r, c, k = input().split()
    r = int(r) - 1
    c = int(c) - 1
    k = int(k)
    array = [[0]*100 for i in range(100)]
    rm = 2
    cm = 2
    count = 0
    for i in range(3):
        x,y,z = input().split()
        x = int(x)
        y = int(y)
        z = int(z)
        array[i][0] = x
        array[i][1] = y
        array[i][2] = z
    while count <= 100:
        if array[r][c] == k:
            print(count)
            sys.exit(0)
        if rm >= cm:
            array, cm = rcalculate(array, rm, cm)
            count += 1
        else:
            array = list(zip(*array))
            array, rm = rcalculate(array, cm, rm)
            array = list(zip(*array))
            count += 1
    print(-1)
    


    
    