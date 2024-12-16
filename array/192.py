from typing import List
from collections import deque
import sys


def is_adjacent(a: str, b: str):
    cont = 0

    if len(a) != len(b):
        return False

    for s, t in zip(a, b):
        if s != t:
            cont += 1

    if cont > 1:
        return False

    return True


def bfs(start: str, target: str, dictionary: List, visited: dict, cont: List):
    if start == target:
        return

    q = deque([[start, 0]])

    while len(q) > 0:
        v = q.popleft()
        visited[v[0]] = 1

        if v[0] == target:
            cont[0] = min(cont[0], v[1])

        for word in dictionary:
            if visited[word] == 0 and is_adjacent(v[0], word):
                q.append([word, v[1] + 1])


dictionary = ["POON", "PLEE", "SAME", "POIE", "PLEA", "PLIE", "POIN"]
start = "TOON"
target = "PLEA"
visited = {item: 0 for item in dictionary}
cont = [sys.maxsize]
bfs(start, target, dictionary, visited, cont)
print(cont[0] + 1)


dictionary = ["ABCD", "EBAD", "EBCD", "XYZA"]
start = "ABCV"
target = "EBAD"
visited = {item: 0 for item in dictionary}
cont = [sys.maxsize]
bfs(start, target, dictionary, visited, cont)
print(cont[0] + 1)
