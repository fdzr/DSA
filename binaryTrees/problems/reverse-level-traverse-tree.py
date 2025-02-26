from collections import deque

# https://www.techiedelight.com/reverse-level-order-traversal-binary-tree/


class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def traverse_level(root: Node) -> deque:
    q = deque([root])
    stack = deque()

    while len(q) > 0:
        curr = q.popleft()

        stack.append(curr.key)

        if curr.left:
            q.append(curr.left)
        if curr.right:
            q.append(curr.right)

    return stack


def traverse_level_reverse(root: Node):
    stack = traverse_level(root)

    while len(stack) > 0:
        print(stack.pop())


def pre_order(root: Node, d: dict, level: int):
    if root is None:
        return

    d.setdefault(level, []).append(root.key)

    pre_order(root.left, d, level + 1)
    pre_order(root.right, d, level + 1)


def traverse_level_reverse_alternative(root: Node):
    d = {}

    pre_order(root, d, 1)

    for index in range(len(d), 0, -1):
        print([i for i in d[index]])


if __name__ == "__main__":
    root = Node(15)
    root.left = Node(10)
    root.right = Node(20)

    root.left.left = Node(8)
    root.left.right = Node(12)

    root.right.left = Node(16)
    root.right.right = Node(25)

    traverse_level_reverse(root)

    traverse_level_reverse_alternative(root)
