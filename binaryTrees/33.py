from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None) -> None:
        self.val = val
        self.left = left
        self.right = right


def pre_order(root1: Optional[TreeNode], root2: Optional[TreeNode]):
    if root2 is None:
        return True
    if root1 is None:
        return False

    if root1.val == root2.val:
        ans = compare(root1, root2)
        if ans is True:
            return ans

    ans1 = pre_order(root1.left, root2)
    ans2 = pre_order(root1.right, root2)

    return ans1 or ans2


def compare(root1, root2):
    if root1 is None and root2 is None:
        return True
    if root1 is not None and root2 is None:
        return False
    if root1 is None and root2 is not None:
        return False
    if root1.val != root2.val:
        return False

    ans1 = compare(root1.left, root2.left)
    ans2 = compare(root1.right, root2.right)

    return ans1 and ans2


tree1 = TreeNode(3)
tree1.left = TreeNode(4)
tree1.right = TreeNode(5)
tree1.left.left = TreeNode(1)
tree1.left.right = TreeNode(2)
tree1.left.right.left = TreeNode(0)

# tree1.right.left = TreeNode(4)
# tree1.right.left.left = TreeNode(1)
# tree1.right.left.right = TreeNode(2)
# tree1.right.left.right.right = TreeNode(9)

tree2 = TreeNode(4)
tree2.left = TreeNode(1)
tree2.right = TreeNode(2)

print(pre_order(tree1, tree2))
