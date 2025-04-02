from typing import List


class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def pre_order(root: Node):
    if root is None:
        return

    print(root.key, end=" ")
    pre_order(root.left)
    pre_order(root.right)


def convert_tree(root: Node):
    if root is None:
        return 0

    sum_l = convert_tree(root.left)
    sum_r = convert_tree(root.right)

    sum_total = sum_l + sum_r + root.key

    root.key = sum_l + sum_r

    return sum_total


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)

    root.left.right = Node(4)

    root.right.left = Node(5)
    root.right.right = Node(6)

    root.right.left.left = Node(7)
    root.right.left.right = Node(8)

    convert_tree(root)

    pre_order(root)
