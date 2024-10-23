from typing import List


# O(n + m)
def fairCandySwap(aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
    a = set(aliceSizes)
    b = set(bobSizes)
    alice_sum = sum(aliceSizes)
    bob_sum = sum(bobSizes)

    half = (alice_sum + bob_sum) // 2
    diff = abs(alice_sum - half)

    if alice_sum < half:
        for elem in aliceSizes:
            if elem + diff in b:
                return [elem, elem + diff]
    else:
        for elem in bobSizes:
            if elem + diff in a:
                return [elem + diff, elem]


print(fairCandySwap([2], [1, 3]))
