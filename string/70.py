

def helper(rest):
    cont = 0
    if rest >= 15:
        acc = rest % 15
        rest = rest // 15
        cont += rest

        if acc >= 5:
            acc_1 = acc % 5
            acc = acc // 5
            cont += acc
            cont += acc_1
        else:
            cont += acc

    elif rest >= 5:
        cont += rest // 5
        cont += rest % 5

    else:
        cont += rest

    return cont


def convertTime(current: str, correct: str) -> int:
    
    current_hours = int(current.split(":")[0])
    current_minutes = int(current.split(":")[1])

    correct_hours = int(correct.split(":")[0])
    correct_minutes = int(correct.split(":")[1])

    cont = 0
    if (correct_minutes - current_minutes) < 0:
        diff = 60 - (current_minutes - correct_minutes)
    else:
        diff = correct_minutes - current_minutes
    cont += helper(diff)
    cont += correct_hours - current_hours
    if correct_minutes < current_minutes:
        cont -= 1

    return cont


if __name__ == "__main__":
    current = "02:35"
    correct = "04:33"
    print(convertTime(current, correct))
