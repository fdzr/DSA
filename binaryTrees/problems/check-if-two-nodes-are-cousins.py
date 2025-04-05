from collections import deque


class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


class Instance:
    def __init__(self, parent: int, level: int):
        self.parent = parent
        self.level = level

    def __eq__(self, other):
        return self.level == other.level and self.parent != other.parent


def check_cousins(root: Node, node1: Node, node2: Node):
    q = deque([(root, None)])
    level = 0

    solution1, solution2 = None, None

    while len(q) > 0:
        n = len(q)

        for _ in range(n):
            temp = q.popleft()

            if solution1 is None and temp[0].key == node1:
                solution1 = Instance(parent=temp[1], level=level)
            if solution2 is None and temp[0].key == node2:
                solution2 = Instance(parent=temp[1], level=level)

            if solution1 is not None and solution2 is not None:
                break

            if temp[0].left is not None:
                q.append((temp[0].left, temp[0].key))
            if temp[0].right is not None:
                q.append((temp[0].right, temp[0].key))

        level += 1

    if solution1 is None or solution2 is None:
        return False

    return solution1 == solution2


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)

    root.left.left = Node(4)
    root.left.right = Node(5)

    root.right.left = Node(6)
    root.right.right = Node(7)

    print(check_cousins(root, 4, 6))
