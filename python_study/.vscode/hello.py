def calScore(ox):
    result = 0
    score = 0
    while ox:
        temp = ox.pop(0)
        if temp == 'O':
            score+=1
            result += score
        else :
            score = 0
    return result


def main():
    n = int(input())
    for i in range(0,n):
        inp = list(input())
        print(calScore(inp))

if __name__ == "__main__":
    main()