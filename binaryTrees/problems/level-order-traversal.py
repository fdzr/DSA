from collections import deque


class Node:
    def __init__(self, key: int):
        self.key = key
        self.left: Node = None
        self.right: Node = None


def level_order_traversal(root: Node):
    q = deque([root])

    while len(q):
        size = len(q)

        for _ in range(size):
            node = q.popleft()
            print(node.key, end=" ")

            if node.left is not None:
                q.append(node.left)
            if node.right is not None:
                q.append(node.right)

        print()


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(3)
    root.right = Node(2)
    root.right.right = Node(4)
    root.right.right.left = Node(6)
    root.right.right.right = Node(5)

    level_order_traversal(root)
