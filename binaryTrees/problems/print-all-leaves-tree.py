from collections import deque


class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def print_all_leaves(root: Node):
    if root is None:
        return

    if root.left is None and root.right is None:
        print(root.key, end=" ")

    print_all_leaves(root.left)
    print_all_leaves(root.right)


def print_all_leaves_bfs(root: Node):
    q = deque([root])

    while len(q) > 0:
        curr = q.popleft()

        if curr.left is None and curr.right is None:
            print(curr.key, end=" ")

        if curr.left:
            q.append(curr.left)
        if curr.right:
            q.append(curr.right)


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)

    root.left.left = Node(4)

    root.right.left = Node(5)
    root.right.right = Node(8)

    root.right.left.left = Node(6)
    root.right.left.right = Node(7)

    root.right.right.left = Node(9)
    root.right.right.right = Node(10)

    print_all_leaves(root)
    print()
    print_all_leaves_bfs(root)
