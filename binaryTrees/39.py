from typing import Optional, List


class TreeNode:
    def __init__(self, k: int):
        self.val = k
        self.left: TreeNode = None
        self.right: TreeNode = None


def sumEvenGrandparent(root: Optional[TreeNode]) -> int:
    sum: List[int] = [0]

    def dfs(
        root: Optional[TreeNode],
        parent: Optional[TreeNode],
        grandpa: Optional[TreeNode],
    ):
        if root is None:
            return

        if grandpa is not None and grandpa.val % 2 == 0:
            sum[0] += root.val

        dfs(root.left, root, parent)
        dfs(root.right, root, parent)

    dfs(root, None, None)

    return sum[0]


if __name__ == "__main__":
    root = TreeNode(6)
    root.left = TreeNode(7)
    root.right = TreeNode(8)
    root.left.left = TreeNode(2)
    root.left.right = TreeNode(7)
    root.left.left.left = TreeNode(9)
    root.left.right.left = TreeNode(1)
    root.left.right.right = TreeNode(4)
    root.right.left = TreeNode(1)
    root.right.right = TreeNode(3)
    root.right.right.right = TreeNode(5)

    print(sumEvenGrandparent(root))
