# https://www.techiedelight.com/truncate-given-binary-tree-remove-nodes-lie-path-sum-less-k/


class TreeNode:
    def __init__(self, k: int):
        self.val: int = k
        self.left: TreeNode = None
        self.right: TreeNode = None


def pre_order(root: TreeNode):
    if root is None:
        return

    print(root.val, end=" ")
    pre_order(root.left)
    pre_order(root.right)


def solution(root: TreeNode, cont: int, k: int, check_condition: bool) -> bool:
    if root is None:
        return False

    cont += root.val
    check_condition[0] = False

    sol_left = solution(root.left, cont, k, check_condition)
    sol_right = solution(root.right, cont, k, check_condition)

    is_removable = False
    answer = None

    if check_condition[0] is False:
        check_condition[0] = True

        if cont < k:
            is_removable = True

        answer = is_removable
    else:
        answer = (
            sol_left and sol_right
            if root.left and root.right
            else sol_left if root.left else sol_right
        )

    if sol_left is True:
        root.left = None
    if sol_right is True:
        root.right = None

    return answer


if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.right.left = TreeNode(4)

    # root.right.left = TreeNode(4)
    # root.right.right = TreeNode(2)

    # root.right.left.left = TreeNode(1)
    # root.right.left.right = TreeNode(7)

    # root.right.right.right = TreeNode(3)

    k = 8
    check_condition = [False]
    solution(root, 0, k, check_condition)
    pre_order(root)
