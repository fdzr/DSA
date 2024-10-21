from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None) -> None:
        self.val = val
        self.left = left
        self.right = right


def pre_order(root1: Optional[TreeNode], root2: Optional[TreeNode]):
    if root1 is None:
        return

    print(root1.val, end=" ")
    pre_order(root1.left, None)
    pre_order(root1.right, None)


def compare(root1, root2):
    pass


tree1 = TreeNode(3)
tree1.left = TreeNode(4)
tree1.right = TreeNode(5)
tree1.left.left = TreeNode(1)
tree1.left.right = TreeNode(2)

tree1.right.left = TreeNode(4)
tree1.right.left.left = TreeNode(1)
tree1.right.left.right = TreeNode(2)
tree1.right.left.right.right = TreeNode(9)

tree2 = TreeNode(4)
tree2.left = TreeNode(1)
tree2.right = TreeNode(2)

pre_order(tree2, None)
