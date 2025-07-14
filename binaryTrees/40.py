from typing import List, Optional


class TreeNode:
    def __init__(self, k: int):
        self.val: int = k
        self.left: TreeNode = None
        self.right: TreeNode = None


def find_index_right_subtree(preorder: List[int], l: int, r: int):
    idx = -1

    for index in range(l, r + 1):
        if preorder[index] > preorder[l]:
            idx = index
            break

    return idx


def insert(preorder: List[int], l: int, r: int) -> Optional[TreeNode]:
    if l > r:
        return None

    index = find_index_right_subtree(preorder, l, r)
    node = TreeNode(preorder[l])

    if l == r:
        return node

    node.left = insert(preorder, l + 1, index - 1 if index != -1 else r)
    node.right = insert(preorder, index if index != -1 else r + 1, r)

    return node


def in_order(root: Optional[TreeNode]):
    if root is None:
        return

    in_order(root.left)
    print(root.val, end=" ")
    in_order(root.right)


def bstFromPreorder(preorder: List[int]) -> Optional[TreeNode]:
    root = insert(preorder, 0, len(preorder) - 1)
    in_order(root)


if __name__ == "__main__":
    preorder = [8, 5, 1, 7, 10, 12]
    # preorder = [4, 2]
    bstFromPreorder(preorder)
