class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def get_successor(root: Node, key: int, last: Node):
    if root is None:
        return None

    node = get_successor(root.right, key, last)
    if node is not None:
        return node

    if root.key == key:
        return last[0]

    last[0] = root

    return get_successor(root.left, key, last)


def in_order(root: Node):
    if root is None:
        return

    in_order(root.left)
    print(root.key, end=" ")
    in_order(root.right)


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)

    root.left.left = Node(4)
    root.left.right = Node(5)

    root.right.left = Node(6)
    root.right.right = Node(7)

    last = [None]
    n = get_successor(root, 4, last)
    print(n.key)
