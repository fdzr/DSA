from typing import List


class Node:
    def __init__(self, key: int):
        self.key = key
        self.left: Node = None
        self.right: Node = None


def pre_order(root: Node):
    if root is None:
        return None

    print(root.key, end=" ")
    pre_order(root.left)
    pre_order(root.right)


def in_order(root: Node):
    if root is None:
        return None

    in_order(root.left)
    print(root.key, end=" ")
    in_order(root.right)


def build_tree(
    preorder: List[int],
    start: int,
    end: int,
):
    if start > end:
        return None

    root = Node(preorder[start])

    if start == end:
        return root

    mid = (1 + start - end) // 2 + end

    root.left = build_tree(preorder, start + 1, mid)
    root.right = build_tree(preorder, mid + 1, end)

    return root


def solution():
    preorder = [1, 2, 4, 5, 3, 6, 7]
    start, end = 0, len(preorder) - 1

    return build_tree(preorder, start, end)


if __name__ == "__main__":
    root = solution()
    in_order(root)
    print()
    pre_order(root)
