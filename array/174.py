def isBadVersion(n): ...


def firstBadVersion(n: int) -> int:
    L, R = 0, n

    while L <= R:
        M = L + (R - L) // 2

        if isBadVersion(M):
            R = M - 1
        else:
            L = M + 1

    return L
