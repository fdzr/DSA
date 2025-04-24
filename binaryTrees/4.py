from typing import Optional


class TreeNode:
    def __init__(self, val: int):
        self.val = val
        self.left: TreeNode = None
        self.right: TreeNode = None


def isSameTree(p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    if p == None and q == None:
        return True

    if p == None or q == None:
        return False

    if p.val != q.val:
        return False

    return isSameTree(p.left, q.left) and isSameTree(p.right, q.right)


if __name__ == "__main__":
    root1 = TreeNode(1)
    root1.left = TreeNode(2)
    root1.right = TreeNode(3)

    root2 = TreeNode(1)
    root2.left = TreeNode(2)
    root2.right = TreeNode(3)

    print(isSameTree(root1, root2))
