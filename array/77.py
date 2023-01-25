from typing import List


def countGoodTriplets(arr: List[int], a: int, b: int, c: int) -> int:
    cont  = 0
    for i in range(len(arr) - 2):
        for j in range(i + 1, len(arr) - 1):
            if abs(arr[i] - arr[j]) <= a:
                for k in range(j + 1, len(arr)):
                    if abs(arr[j] - arr[k]) <= b and abs(arr[i] - arr[k]) <= c:
                        cont += 1

    return cont


if __name__ == "__main__":
    arr = [1,1,2,2,3]
    print(countGoodTriplets(arr, 0, 0, 1))


