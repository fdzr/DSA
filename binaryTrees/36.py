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

    # def __repr__(self):
    #     print(f"{self.value} - {self.cont} - {self.max_path}")


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

            cont[0] = max(cont[0], pack.cont)

    elif sol_left.value is not None and sol_right.value is None:
        if sol_left.value == root.val:
            pack.cont = sol_left.cont + 1
            if sol_left.max_path is not None:
                pack.cont = 1 + sol_left.max_path

            cont[0] = max(cont[0], pack.cont)

    else:
        if root.val == sol_left.value and root.val == sol_right.value:
            pack.cont = sol_left.cont + sol_right.cont
            pack.max_path = max(sol_left.cont, sol_right.cont)
            cont[0] = max(cont[0], pack.cont)
        elif root.val == sol_left.value:
            pack.cont = sol_left.cont + 1

            cont[0] = max(cont[0], pack.cont)
        elif root.val == sol_right.value:
            pack.cont = sol_right.cont + 1

            cont[0] = max(cont[0], pack.cont)

    pack.value = root.val
    # pack.cont = 0

    return pack


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
