answer = 0

def makeSol(numbers, target, now):
    global answer

    if(len(numbers) == 1):
        if(now + numbers[-1] == target):
            answer+=1
        if(now - numbers[-1] == target):
            answer+=1
        return answer

    makeSol(numbers[1:], target, now+numbers[0])
    makeSol(numbers[1:], target, now-numbers[0])

    return answer

def solution(numbers, target):
    global answer

    makeSol(numbers, target, 0)

    return answer