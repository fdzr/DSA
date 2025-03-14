from typing import List


class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def pre_order(root: Node):
    if root is None:
        return

    print(root.key, end=" ")
    pre_order(root.left)
    pre_order(root.right)


def build_tree(preorder: List[int], inorder: List[int], pre_index: List[int]):
    if not inorder:
        return None

    elem = preorder[pre_index[0]]
    pre_index[0] += 1

    root = Node(elem)

    inorder_index = inorder.index(elem)

    root.left = build_tree(
        preorder,
        inorder[:inorder_index],
        pre_index,
    )
    root.right = build_tree(
        preorder,
        inorder[inorder_index + 1 :],
        pre_index,
    )

    return root


if __name__ == "__main__":
    preorder = [0, 1, 3, 4, 2, 5]
    inorder = [3, 1, 4, 0, 5, 2]
    pre_index = [0]

    root = build_tree(preorder, inorder, pre_index)
    pre_order(root)
