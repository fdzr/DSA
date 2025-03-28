from typing import List

type Matrix = List[List[int]]


class Node:
    def __init__(self, key: int):
        self.key = key
        self.left: Node = None
        self.right: Node = None


def count_nodes(root: Node):
    if root is None:
        return 0

    return count_nodes(root.left) + count_nodes(root.right) + 1


def build_ancestor_matrix(
    root: Node,
    matrix: Matrix,
    ancestors: List[int],
):
    if root is None:
        return

    for an in ancestors:
        matrix[an][root.key] = 1

    ancestors.append(root.key)

    build_ancestor_matrix(
        root.left,
        matrix,
        ancestors,
    )
    build_ancestor_matrix(
        root.right,
        matrix,
        ancestors,
    )

    ancestors.pop()


def solution(root: Node):
    n_nodes = count_nodes(root)
    matrix = [[0] * n_nodes for _ in range(n_nodes)]
    ancestors = []

    build_ancestor_matrix(
        root,
        matrix,
        ancestors,
    )

    print(matrix)


root = Node(5)
root.left = Node(1)
root.right = Node(2)

root.left.left = Node(0)
root.left.right = Node(4)

root.right.left = Node(3)

solution(root)
