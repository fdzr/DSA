class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def find_lca(root: Node, n1: int, n2: int):
    if root is None:
        return None

    if root.key in [n1, n2]:
        return root

    left_lca = find_lca(root.left, n1, n2)
    right_lca = find_lca(root.right, n1, n2)

    if left_lca and right_lca:
        return root

    return left_lca if left_lca else right_lca


def is_key_present(root: Node, key: int):
    if root is None:
        return False

    if (
        root.key == key
        or is_key_present(root.left, key)
        or is_key_present(root.right, key)
    ):
        return True

    return False


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)

    root.left.right = Node(4)

    root.right.left = Node(5)
    root.right.right = Node(6)

    root.right.left.left = Node(7)
    root.right.left.right = Node(8)

    n1, n2 = 6, 7
    lca = find_lca(
        root,
        n1,
        n2,
    )
    print(lca.key)
