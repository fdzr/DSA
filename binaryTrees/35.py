from typing import List


class TreeNode:
    def __init__(self, val: int):
        self.val = val
        self.left = None
        self.right = None


def solution(root: TreeNode, cont: List[int]):
    if root is None:
        return (0, 0)

    sol_left = solution(root.left, cont)
    sol_right = solution(root.right, cont)

    sum_nodes = sol_left[0] + sol_right[0] + root.val
    cant_nodes = sol_left[1] + sol_right[1] + 1

    if sum_nodes // cant_nodes == root.val:
        cont[0] += 1

    return (sum_nodes, cant_nodes)


def averageOfSubtree(root: TreeNode) -> int:
    cont = [0]

    solution(root, cont)

    return cont[0]


if __name__ == "__main__":
    root = TreeNode(4)
    root.left = TreeNode(8)
    root.right = TreeNode(5)
    root.left.left = TreeNode(0)
    root.left.right = TreeNode(1)
    root.right.right = TreeNode(6)

    print(averageOfSubtree(root))
