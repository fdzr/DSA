from typing import List


def partition_k_equal_sum(arr: List, subsets: List, k: int, index: int):
    if index == len(arr):
        return all(elem == k for elem in subsets)

    for idx in range(len(subsets)):
        if subsets[idx] + arr[index] > k:
            continue

        subsets[idx] += arr[index]

        if partition_k_equal_sum(arr, subsets, k, index + 1) is True:
            return True

        subsets[idx] -= arr[index]

    return False


subsets = [0] * 4
k = 5
index = 0
arr = [4, 3, 2, 3, 5, 1, 2]
print(partition_k_equal_sum(arr, subsets, k, index))
