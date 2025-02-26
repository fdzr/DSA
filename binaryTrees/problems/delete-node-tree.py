from collections import deque


class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def in_order(root: Node):
    if root is None:
        return

    in_order(root.left)
    print(root.key, end=" ")
    in_order(root.right)


def find_deepest_and_right_most_node(root: Node):
    q = deque([(root, None, True)])
    right_most, parent = None, None

    while len(q) > 0:
        n = len(q)

        for _ in range(n):
            curr = q.popleft()

            if curr[2] == True:
                right_most = curr[0]
                parent = curr[1]

            if curr[0].left:
                q.append((curr[0].left, curr[0], False))
            if curr[0].right:
                q.append((curr[0].right, curr[0], True))

    return right_most, parent


def delete_node(root: Node, key: int):
    q = deque([root])
    target_node = None

    while len(q) > 0:
        curr = q.popleft()

        if curr.key == key:
            target_node = curr
            break

        if curr.left:
            q.append(curr.left)
        if curr.right:
            q.append(curr.right)

    deepest_node, parent_deepest_node = find_deepest_and_right_most_node(root)

    target_node.key = deepest_node.key
    parent_deepest_node.right = None


if __name__ == "__main__":
    # root = Node(1)
    # root.left = Node(2)
    # root.right = Node(3)

    # root.left.left = Node(4)
    # root.left.right = Node(5)

    # root.right.right = Node(6)

    # root.left.right.left = Node(7)

    root = Node(13)
    root.left = Node(12)
    root.right = Node(10)

    root.left.left = Node(4)
    root.left.right = Node(19)

    root.right.left = Node(16)
    root.right.right = Node(9)

    in_order(root)
    print()

    delete_node(root, 12)

    in_order(root)

    # curr, parent = find_deepest_and_right_most_node(root)

    # print(curr.key)
    # print(parent.key)
