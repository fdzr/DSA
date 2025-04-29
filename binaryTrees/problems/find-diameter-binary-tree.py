from typing import List

# https://www.geeksforgeeks.org/diameter-of-a-binary-tree/


class TreeNode:
    def __init__(self, key: int):
        self.val: int = key
        self.left: TreeNode = None
        self.right: TreeNode = None


def find_diameter(root: TreeNode, diameter: List[int]):
    if root is None:
        return 0

    sol_left = find_diameter(root.left, diameter)
    sol_right = find_diameter(root.right, diameter)

    diameter[0] = max(diameter[0], sol_left + sol_right)

    return max(sol_left, sol_right) + 1


if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)

    root.left.left = TreeNode(4)

    root.left.left.left = TreeNode(5)
    root.left.left.right = TreeNode(6)

    root.left.left.left.left = TreeNode(7)
    root.left.left.right.left = TreeNode(8)

    root.left.left.left.left.left = TreeNode(9)
    root.left.left.left.left.left.left = TreeNode(10)

    root.left.left.right.left.right = TreeNode(11)
    root.left.left.right.left.right.right = TreeNode(12)

    diameter: List[int] = [0]
    find_diameter(root, diameter)
    print(diameter[0])
