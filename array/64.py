def helper():
    ans = [0] * 38
    ans[1] = 1
    ans[2] = 1
    ans[3] = 2
    for i in range(4, 38):
        ans[i] = ans[i - 3] + ans[i - 2] + ans[i - 1]

    return ans


def tribonacci(n: int) -> int:
    ans = helper()
    return ans[n]


if __name__ == "__main__":
    n = 25
    print(tribonacci(n))