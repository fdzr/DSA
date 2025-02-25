class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def find_node(root: Node, key: int):
    if root is None:
        return False

    if root.key == key:
        return True

    l = find_node(root.left, key)
    r = find_node(root.right, key)

    if l or r:
        return True

    return False


def find_node2(root: Node, key: int):
    if root is None:
        return False

    if root.key == key:
        return True  # Early return, no further recursion

    return find_node2(root.left, key) or find_node2(root.right, key)


if __name__ == "__main__":
    root = Node(0)
    root.left = Node(1)
    root.right = Node(2)

    root.left.left = Node(3)
    root.left.right = Node(4)

    root.left.left.left = Node(7)
    root.left.right.left = Node(8)
    root.left.right.right = Node(9)

    root.right.left = Node(5)
    root.right.right = Node(6)

    print(find_node2(root, 5))
