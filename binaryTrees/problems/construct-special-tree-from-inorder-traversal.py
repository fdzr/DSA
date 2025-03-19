from typing import List


class Node:
    def __init__(self, key: int):
        self.key = key
        self.left: Node = None
        self.right: Node = None


def in_order(root: Node):
    if root is None:
        return

    in_order(root.left)
    print(root.key, end=" ")
    in_order(root.right)


def help_max(inorder: List[int], start: int, end: int):
    max = -1
    index_arr = -1

    for index in range(start, end + 1):
        if inorder[index] > max:
            max = inorder[index]
            index_arr = index

    return index_arr


def build_tree(inorder, start, end):
    if start > end:
        return root

    max_index = help_max(inorder, start, end)

    root = Node(inorder[max_index])

    if start == end:
        return root

    root.left = build_tree(inorder, start, max_index - 1)
    root.right = build_tree(inorder, max_index + 1, end)

    return root


def solution():
    inorder = [5, 10, 40, 30, 28]
    in_order(build_tree(inorder, 0, len(inorder) - 1))


if __name__ == "__main__":
    solution()
