from collections import deque


class Node:
    def __init__(self, key: int):
        self.key = key
        self.left: Node = None
        self.right: Node = None


def insert(root: None, key: int):
    if root is None:
        return Node(key)

    queue = deque([root])

    while len(queue) > 0:
        temp = queue.popleft()

        if temp.left is None:
            temp.left = Node(key)
            break
        else:
            queue.append(temp.left)

        if temp.right is None:
            temp.right = Node(key)
            break
        else:
            queue.append(temp.right)

    return root


def pre_order(root: Node):
    if root is None:
        return

    print(root.key, end=" ")
    pre_order(root.left)
    pre_order(root.right)


if __name__ == "__main__":
    root = Node(4)
    root.left = Node(3)
    root.right = Node(2)

    pre_order(root)

    root = insert(root, 1)
    root = insert(root, 5)
    root = insert(root, 6)
    root = insert(root, 7)

    print()

    pre_order(root)
