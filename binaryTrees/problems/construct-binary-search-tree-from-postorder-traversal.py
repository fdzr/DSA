from typing import List
import math


class Node:
    def __init__(self, key: int):
        self.key = key
        self.left: Node = None
        self.right: Node = None


def in_order(root: Node):
    if root is None:
        return None

    in_order(root.left)
    print(root.key, end=" ")
    in_order(root.right)


def find_index(postorder: List[int], l: int, r: int):
    i = -1
    for idx in range(l, r):
        if postorder[idx] < postorder[r]:
            i = idx

    return i


def build_tree(postorder: List[int], start: int, end: int):
    if start > end:
        return None

    root = Node(postorder[end])

    if start == end:
        return root

    postorder_index = find_index(postorder, start, end)

    root.left = build_tree(postorder, start, postorder_index)
    root.right = build_tree(
        postorder,
        postorder_index + 1 if postorder_index != -1 else start,
        end - 1,
    )

    return root


def solution():
    postorder = [1, 8, 7, 5, 60, 50, 40, 10]
    start, end = 0, len(postorder) - 1
    root = build_tree(postorder, start, end)
    in_order(root)


if __name__ == "__main__":
    solution()
