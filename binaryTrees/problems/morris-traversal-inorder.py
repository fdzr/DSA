class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def morris_traversal_inorder(root: Node):
    res = []
    curr = root

    while curr is not None:
        if curr.left is None:
            res.append(curr.key)
            curr = curr.right
        else:
            prev = curr.left
            while prev.right is not None and prev.right != curr:
                prev = prev.right

            if prev.right is None:
                prev.right = curr
                curr = curr.left
            else:
                prev.right = None
                res.append(curr.key)
                curr = curr.right

    return res


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    res = morris_traversal_inorder(root)

    for d in res:
        print(d, end=" ")
