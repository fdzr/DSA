from collections import deque


class Node:
    def __init__(self, key: int):
        self.key = key
        self.left = None
        self.right = None


def get_height(root: Node):
    if root is None:
        return 0

    l = 1 + get_height(root.left)
    r = 1 + get_height(root.right)

    return max(l, r)


def get_height_bfs(root: Node):
    queue = deque([root])
    h = 0

    while len(queue) > 0:
        size = len(queue)

        for _ in range(size):
            node = queue.popleft()
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)

        h += 1

    return h - 1


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(4)

    root.left.left = Node(3)
    root.right.right = Node(5)
    root.right.right.left = Node(6)
    root.right.right.right = Node(7)

    print(get_height(root) - 1)
    print(get_height_bfs(root))
