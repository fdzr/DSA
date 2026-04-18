def mirrorDistance(n: int) -> int:
    return abs(n - int("".join(list(reversed(str(n))))))


n = 7
print(mirrorDistance(n))
