from typing import Optional

# https://www.geeksforgeeks.org/dsa/print-bst-keys-in-given-range-o1-space/


class TreeNode:
    def __init__(self, k: int):
        self.val: int = k
        self.left: TreeNode = None
        self.right: TreeNode = None


def in_order(root: Optional[TreeNode], n1: int, n2: int):
    if root is None:
        return

    in_order(root.left, n1, n2)
    if n1 <= root.val <= n2:
        print(root.val, end=" ")
    in_order(root.right, n1, n2)


if __name__ == "__main__":
    root = TreeNode(22)
    root.left = TreeNode(12)
    root.right = TreeNode(30)
    root.left.left = TreeNode(8)
    root.left.right = TreeNode(20)

    n1, n2 = 1, 10
    in_order(root, n1, n2)
