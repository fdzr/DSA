from typing import List


def reverse(nums: list, start: int, end: int):
    while start < end:
        temp = nums[start]
        nums[start] = nums[end]
        nums[end] = temp
        start += 1
        end -= 1


def processQueries(queries: List[int], m: int):
    p = list(range(1, m + 1))
    ans = []

    for item in queries:
        index = p.index(item)
        reverse(p, 0, index)
        reverse(p, 1, index)
        ans.append(index)

    return ans


if __name__ == "__main__":
    queries = [7, 5, 5, 8, 3]
    print(processQueries(queries, 8))
