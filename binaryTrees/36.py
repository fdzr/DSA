from typing import Optional, Any, List


class TreeNode:
    def __init__(self, val: int):
        self.val = val
        self.left: TreeNode = None
        self.right: TreeNode = None


def solution(root: TreeNode, cont: List[int]) -> int:
    if root is None:
        return 0

    sol_left = solution(root.left, cont)
    sol_right = solution(root.right, cont)

    sl = sol_left + 1 if root.left and root.left.val == root.val else 0
    sr = sol_right + 1 if root.right and root.right.val == root.val else 0

    cont[0] = max(cont[0], sr + sl)

    return max(sl, sr)


def longestUnivaluePath(root: Optional[TreeNode]) -> int:
    cont = [0]
    solution(root, cont)
    return cont[0]


if __name__ == "__main__":
    root = TreeNode(1)
    root.right = TreeNode(1)
    root.right.left = TreeNode(1)
    root.right.right = TreeNode(1)
    root.right.right.left = TreeNode(1)

    root.right.left.left = TreeNode(1)
    root.right.left.right = TreeNode(1)

    print(longestUnivaluePath(root))
