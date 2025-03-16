from typing import List


class Node:
    def __init__(self, key: int):
        self.key = key
        self.left: Node = None
        self.right: Node = None


def build_tree(
    postorder: List[int],
    preorder: List[int],
    pre_index: List[int],
    post_start: int,
    post_end: int,
):
    if pre_index[0] >= len(postorder) or post_start > post_end:
        return None

    value = preorder[pre_index[0]]
    root = Node(value)

    pre_index[0] += 1

    if post_start == post_end:
        return root

    left_subtree_value = preorder[pre_index[0]]
    left_subtree_index = postorder.index(left_subtree_value)

    root.left = build_tree(
        postorder,
        preorder,
        pre_index,
        post_start,
        left_subtree_index,
    )
    root.right = build_tree(
        postorder,
        preorder,
        pre_index,
        left_subtree_index + 1,
        post_end - 1,
    )

    return root


def pre_order(root: Node):
    if root is None:
        return

    print(root.key, end=" ")
    pre_order(root.left)
    pre_order(root.right)


def in_order(root: Node):
    if root is None:
        return

    in_order(root.left)
    print(root.key, end=" ")
    in_order(root.right)


def post_order(root: Node):
    if root is None:
        return

    post_order(root.left)
    post_order(root.right)
    print(root.key, end=" ")


def solution():
    pre_index = [0]
    preorder = [1, 2, 4, 8, 9, 5, 3, 6, 7]
    postorder = [8, 9, 4, 5, 2, 6, 7, 3, 1]

    root = build_tree(
        postorder,
        preorder,
        pre_index,
        0,
        len(postorder) - 1,
    )
    pre_order(root)
    print()
    post_order(root)
    print()
    in_order(root)


if __name__ == "__main__":
    solution()
