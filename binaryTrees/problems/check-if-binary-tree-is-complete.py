from collections import deque


class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def is_complete_binary_tree(root: Node):
    q: deque[Node] = deque([root])
    incomplete: bool = False

    while len(q) > 0:

        for _ in range(len(q)):
            temp = q.popleft()

            if temp.left is None and temp.right is not None:
                return False

            if incomplete is True and (temp.left is not None or temp.right is not None):
                return False

            if temp.left is not None:
                q.append(temp.left)
            else:
                incomplete = True
            if temp.right is not None:
                q.append(temp.right)
            else:
                incomplete = True

    return True


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)

    root.left.left = Node(4)
    root.left.right = Node(5)

    # root.right.left = Node(6)
    root.right.right = Node(7)

    print(is_complete_binary_tree(root))
