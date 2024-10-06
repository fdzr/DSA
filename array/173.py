def isPerfectSquare(num: int) -> bool:
    if num == 1:
        return True

    n = num // 2

    for div in range(1, n + 1):
        if div * div == num:
            return True
        elif div * div > num:
            return False

    return False


print(isPerfectSquare(14))
