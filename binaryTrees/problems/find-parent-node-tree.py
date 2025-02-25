class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def find_parent(root: Node, key: int, parent: Node):
    if root is None:
        return -1

    if root.key == key:
        return parent

    l = find_parent(root.left, key, root.key)
    if l != -1:
        return l

    r = find_parent(root.right, key, root.key)
    if r != -1:
        return r

    return -1


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(7)
    root.right = Node(3)

    root.left.left = Node(4)
    root.left.right = Node(5)

    root.right.right = Node(6)

    print(
        find_parent(
            root,
            3,
            -1,
        )
    )
