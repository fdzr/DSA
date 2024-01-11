from typing import List
import math
from functools import cmp_to_key


def cmp(a: List[int]):
    dist_A = math.sqrt(math.pow(a[0] - 0, 2) + math.pow(a[1] - 0, 2))

    return dist_A


def kClosest(points: List[List[int]], k: int) -> List[List[int]]:
    points = sorted(points, key=cmp)

    return points[:k]


print(kClosest([[3, 3], [5, -1], [-2, 4]], k=2))
