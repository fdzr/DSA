from typing import Optional, List


class TreeNode:
    def __init__(self, val: int):
        self.val: int = val
        self.left: TreeNode = None
        self.right: TreeNode = None


def in_order(root: Optional[TreeNode], values: List[int]):
    if root is None:
        return

    in_order(root.left, values)
    values.append(root.val)
    in_order(root.right, values)


def convert(root: Optional[TreeNode], mapping: dict[int, int]):
    if root is None:
        return

    root.val = mapping[root.val]
    convert(root.left, mapping)
    convert(root.right, mapping)


def convertBST(root: Optional[TreeNode]) -> Optional[TreeNode]:
    values = []
    in_order(root, values)
    values.sort(reverse=True)
    freq2map = {}

    cont = 0
    for elem in values:
        cont += elem
        freq2map[elem] = cont

    convert(root, freq2map)

    return root


def in_order2(root: Optional[TreeNode]):
    if root is None:
        return

    in_order2(root.left)
    print(root.val, end=" ")
    in_order2(root.right)


if __name__ == "__main__":
    root = TreeNode(4)
    root.left = TreeNode(1)
    root.right = TreeNode(6)
    root.left.left = TreeNode(0)
    root.left.right = TreeNode(2)
    root.left.right.right = TreeNode(3)
    root.right.left = TreeNode(5)
    root.right.right = TreeNode(7)
    root.right.right.right = TreeNode(8)

    in_order2(convertBST(root))
