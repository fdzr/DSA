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


def build_tree(
    preorder: List[int],
    start: int,
    end: int,
):
    if start > end:
        return None

    mid = (start - end) // 2 + end

    root = Node(preorder[start])

    root.left = build_tree(preorder, start + 1, mid)
    root.right = build_tree(preorder, mid + 1, end)

    return root


def solution():
    preorder = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]
    start, end = 0, len(preorder) - 1

    return build_tree(preorder, start, end)


if __name__ == "__main__":
    pre_order(solution())
