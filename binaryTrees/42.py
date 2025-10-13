from typing import List, Optional
import copy


class TreeNode:
    def __init__(self, k: int):
        self.val: int = k
        self.left: TreeNode = None
        self.right: TreeNode = None


def pathSum(root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
    temp: List[int] = []
    ans: List[int] = []
    cont = 0

    def dfs(root, ans, targetSum, temp, cont):
        if root is None:
            return

        cont += root.val
        temp.append(root.val)

        if root.left is None and root.right is None and cont == targetSum:
            ans.append(copy.deepcopy(temp))
            temp.pop()
            return

        dfs(root.left, ans, targetSum, temp, cont)
        dfs(root.right, ans, targetSum, temp, cont)

        temp.pop()

    dfs(root, ans, targetSum, temp, cont)

    return ans


targetSum = 22
root = TreeNode(5)
root.left = TreeNode(4)
root.right = TreeNode(8)
root.left.left = TreeNode(11)
root.left.left.left = TreeNode(7)
root.left.left.right = TreeNode(2)

root.right.left = TreeNode(13)
root.right.right = TreeNode(4)
root.right.right.left = TreeNode(5)
root.right.right.right = TreeNode(1)

print(pathSum(root, 22))
