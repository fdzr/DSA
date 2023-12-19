import sys

data = open(sys.argv[1]).read().splitlines()
input = [list(map(int, item.strip().split())) for item in data]


def diff(v: list[int]):
    res = []
    for i in range(1, len(v)):
        res.append(v[i] - v[i - 1])

    return res


def extrapolate2part(nums: list[int]):
    diff = 0
    startNumber = nums[-1]

    for i in range(len(nums) - 1, 0, -1):
        diff = nums[i - 1] - startNumber
        startNumber = diff

    return diff


cont = 0
part2 = 0
for v in input:
    startValues = []
    startValues.append(v[0])

    cont += v[-1]
    res = diff(v)
    cont += res[-1]
    startValues.append(res[0])
    while all([e == res[0] for e in res]) is False:
        res = diff(res)
        cont += res[-1]
        startValues.append(res[0])

    part2 += extrapolate2part(startValues)


print(cont)
print(part2)
