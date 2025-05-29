from typing import Optional, Any, List


class TreeNode:
    def __init__(self, val: int):
        self.val = val
        self.left: TreeNode = None
        self.right: TreeNode = None


class Pack:
    def __init__(
        self,
        value: Optional[int] = None,
        cont: int = 0,
        max_path: Optional[int] = None,
    ):
        self.value: Optional[int] = value
        self.cont: int = cont
        self.max_path: Optional[int] = max_path


def solution(root: TreeNode, cont: List[int]) -> tuple[Optional[Any], int]:
    if root is None:
        return Pack()

    sol_left = solution(root.left, cont)
    sol_right = solution(root.right, cont)

    pack = Pack()
    if sol_left.value is None and sol_right.value is None:
        pack.value = root.val

    elif sol_left.value is None and sol_right.value is not None:
        if sol_right.value == root.val:
            pack.cont = sol_right.cont + 1
            if sol_right.max_path is not None:
                pack.cont = 1 + sol_right.max_path
            pack.value = root.val
        cont[0] = max(cont[0], pack.cont)

    elif sol_left.value is not None and sol_right.value is None:
        if sol_left.value == root.val:
            pack.cont = sol_left.cont + 1
            if sol_left is not None:
                pack.cont = 1 + sol_left.max_path
            pack.value = root.val
        cont[0] = max(cont[0], pack.cont)

    else:
        if root.val == sol_left.value and root.value == sol_right.value:
            pack.cont = sol_left.value + sol_right.value
            pack.max_path = max(sol_left.cont, sol_right.cont)
        elif root.val == sol_left.value:
            pack.cont = sol_left.cont + 1
            pack.value = root.val
        elif root.val == sol_right.value:
            pack.cont = sol_right.cont + 1
            pack.value = root.val

        cont[0] = max(cont[0], pack.cont)

        pack.value = root.val
        pack.cont = 0

    return pack


def longestUnivaluePath(root: Optional[TreeNode]) -> int:
    cont = [0]
    sol = solution(root, cont)
    return cont[0]


if __name__ == "__main__":
    root = TreeNode(5)
    root.left = TreeNode(4)
    root.right = TreeNode(5)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(1)
    root.right.right = TreeNode(5)

    print(longestUnivaluePath(root))
