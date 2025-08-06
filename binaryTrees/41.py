from typing import Optional, List
import copy


class TreeNode:
    def __init__(self, k: int):
        self.val: int = k
        self.left: TreeNode = None
        self.right: TreeNode = None


def solution(root: Optional[TreeNode], cad: List[str], answer: List[str]):
    if root is None:
        return

    cad.append(chr(root.val + 97))

    if root.left is None and root.right is None:
        candidate = "".join(reversed(cad))
        answer[0] = candidate if answer[0] is None else min(candidate, answer[0])

    solution(root.left, cad, answer)
    solution(root.right, cad, answer)

    cad.pop(-1)


def smallestFromLeaf(root: Optional[TreeNode]) -> str:
    cad, answer = [], [None]
    solution(root, cad, answer)
    return "".join(answer)


if __name__ == "__main__":
    root = TreeNode(2)
    root.left = TreeNode(2)
    root.right = TreeNode(1)
    root.left.right = TreeNode(1)
    root.left.right.left = TreeNode(0)
    root.right.left = TreeNode(0)

    print(smallestFromLeaf(root))
