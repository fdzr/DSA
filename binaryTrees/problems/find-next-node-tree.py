from collections import deque


class Node:
    def __init__(self, key: int):
        self.key = key
        self.left: Node = None
        self.right: Node = None


def find_next_node(root: Node, key: int):
    q = deque([root])
    next_node = None
    found = False

    while len(q) > 0:
        n = len(q)

        for _ in range(n):
            node = q.popleft()
            if node.key == key:
                found = True
                continue
            if found is True:
                next_node = node
                break

            if node.left is not None:
                q.append(node.left)
            if node.right is not None:
                q.append(node.right)

        if found is True and next_node is not None:
            return next_node.key

    return next_node


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)

    root.left.left = Node(4)
    root.left.right = Node(5)

    root.right.right = Node(6)

    root.right.right.left = Node(7)
    root.right.right.right = Node(8)

    for node in [2, 5, 7, 8]:
        print(find_next_node(root, node))
