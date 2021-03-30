if __name__ == "__main__":
    n = input()
    n = int(n)
    inp = list()
    candy = []
    for i in range(n):
        print(candy)
        inp = input().split()
        inp = list(map(int,inp))
        if inp[0] == 1:
            print('hi')
        else:
            #if len(candy) == 0 or len(candy) == 1:
            #    temp = [inp[1],inp[2]]
            #    candy.append(temp)
            exl = len(candy)
            for i in range(len(candy)):
                if inp[1] == candy[i][0]:
                    candy[i][1] += inp[2]
                    break
                elif inp[1] > candy[i][0]:
                    temp = [inp[1],inp[2]]
                    candy.insert(i+1,temp)
                    break

            if i == exl:
                temp = [inp[1],inp[2]]
                candy.append(temp)
            