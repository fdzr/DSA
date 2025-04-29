from typing import List

# https://www.geeksforgeeks.org/subtree-given-sum-binary-tree/


class TreeNode:
    def __init__(self, key: int):
        self.val: int = key
        self.left: TreeNode = None
        self.right: TreeNode = None


def has_subtree_sum(root: TreeNode, value_sum: int, ans: List[bool]):
    if root is None:
        return 0

    answer_left = has_subtree_sum(root.left, value_sum, ans)
    answer_right = has_subtree_sum(root.right, value_sum, ans)

    sum_subtree = answer_left + answer_right + root.val

    if sum_subtree == value_sum:
        ans[0] = True

    return sum_subtree


if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    key = 6
    ans = [False]
    has_subtree_sum(root, key, ans)
    print(ans)
