class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def get_level(root: Node, key: int, level: int):
    if root is None:
        return -1

    if root.key == key:
        return level

    l = get_level(root.left, key, level + 1)
    if l != -1:
        return l

    r = get_level(root.right, key, level + 1)
    if r != -1:
        return r

    return -1


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)
    root.right.left = Node(6)
    root.right.right = Node(7)

    target = 5
    print(get_level(root, target, 1))
