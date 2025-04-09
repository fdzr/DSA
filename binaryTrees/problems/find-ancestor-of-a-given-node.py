from typing import List


class Node:
    def __init__(self, key: int):
        self.key = key
        self.left: Node = None
        self.right: Node = None


def find_ancestor(root: Node, node: int):
    if root is None:
        return False

    if root.key == node:
        return True

    ans_l = find_ancestor(root.left, node)
    ans_r = find_ancestor(root.right, node)

    if ans_l or ans_r:
        print(root.key)

    return ans_l or ans_r


if __name__ == "__main__":
    root = Node(15)
    root.left = Node(10)
    root.right = Node(20)

    root.left.left = Node(8)
    root.left.right = Node(12)

    root.right.left = Node(16)
    root.right.right = Node(25)

    root.right.left.left = Node(18)
    # root.right.right.right = Node(9)

    find_ancestor(root, 18)
