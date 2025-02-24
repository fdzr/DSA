from collections import deque


class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def get_node(root: Node, key: int):
    q = deque([root])
    aux = None

    while len(q) > 0:
        node = q.popleft()

        if node.key == key:
            aux = node
            break

        if node.left is not None:
            q.append(node.left)
        if node.right is not None:
            q.append(node.right)

    return aux


def get_node_depth(root: Node, key: int):
    q = deque([root])
    depth = 0
    flag = False

    while len(q) > 0:
        n = len(q)

        for _ in range(n):
            node = q.popleft()

            if node.key == key:
                flag = True
                break

            if node.left is not None:
                q.append(node.left)
            if node.right is not None:
                q.append(node.right)

        depth += 1

        if flag is True:
            break

    return depth - 1


def get_node_height(root: Node, key: int):
    node = get_node(root, key)
    height = 0

    q = deque([node])

    while len(q) > 0:
        n = len(q)

        for _ in range(n):
            nn = q.popleft()

            if nn.left is not None:
                q.append(nn.left)
            if nn.right is not None:
                q.append(nn.right)

        height += 1

    return height - 1


if __name__ == "__main__":
    root = Node(5)
    root.left = Node(10)
    root.right = Node(15)
    root.left.left = Node(20)
    root.left.right = Node(25)
    root.right.left = Node(30)
    root.right.right = Node(35)
    root.left.right.right = Node(45)

    key = 10

    print(
        f"depth 25: ",
        get_node_depth(root, key),
    )
    print(
        f"height 25: ",
        get_node_height(root, key),
    )
