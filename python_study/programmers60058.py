
def checkGood(p):
    checker = []
    result = False
    if(not p):
        return result

    while(True):
        if(not p):
            break

        if(len(checker) == 0):
            checker.append(p[0])
            p = p[1:]
            continue
        if(checker[-1] == '('):
            if(p[0] == ')'):
                checker.pop()
            else:
                checker.append(p[0])
            p = p[1:]
        else:
            checker.append(p[0])
            p = p[1:]

    if( len(checker) == 0):
        result = True

    return result

def reverseAnswer(p):
    result = ''
    for a in p:
        if(a == '('):
            result += ')'
        else:
            result += '('
    return result

def findSol(p):
    answer = ''
    if(checkGood(p)):
        return p
    if(not p ):
        return ''
    rCont = 0
    lCout = 0

    u = ''
    v = ''

    for i in range(len(p)):
        if(p[i] == '('):
            rCont+=1
        elif(p[i] == ')'):
            lCout+=1

        if(rCont != 0 and lCout != 0 and rCont == lCout):
            u = p[:i+1]
            v = p[i+1:]
            break

    if(checkGood(u)):
        answer = u + findSol(v)
    else:
        answer += '('
        answer += findSol(v)
        answer += ')'
        answer += reverseAnswer(u[1:-1])
    return answer

def solution(p):

    answer = ''
    if( len(p) == 0):
        return answer

    answer = findSol(p)

    return answer

def main():
    p = '()))((()'
    print(findSol(p))

if __name__ == "__main__":
    main()