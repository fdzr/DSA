from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None) -> None:
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def inOrder(self, root: Optional[TreeNode], elems: list):
        if root is None:
            return

        self.inOrder(root.left, elems)

        if root:
            elems.append(root.val)

        self.inOrder(root.right, elems)

    @classmethod
    def getMinimumDifference(cls, root: Optional[TreeNode]) -> int:
        min_value = float("inf")
        elems = []

        cls().inOrder(root, elems)

        for index in range(1, len(elems)):
            min_value = min(min_value, abs(elems[index] - elems[index - 1]))

        return min_value


if __name__ == "__main__":
    root = TreeNode(4)
    root.left = TreeNode(2)
    root.right = TreeNode(6)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(3)

    print(Solution.getMinimumDifference(root))
