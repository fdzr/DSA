from collections import deque

# https://www.geeksforgeeks.org/dsa/check-weather-given-binary-tree-perfect-not/


class TreeNode:
    def __init__(self, k: int):
        self.val = k
        self.left: TreeNode = None
        self.right: TreeNode = None


def check_if_binary_tree_is_perfect(root: TreeNode):
    d = deque([root])
    level = 0

    while len(d) > 0:
        n = len(d)
        cont = 0

        for _ in range(n):
            nodo = d.popleft()
            if nodo.left:
                d.append(nodo.left)
            if nodo.right:
                d.append(nodo.right)

            cont += 1

        if cont != 2**level:
            return False

        level += 1

    return True


if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(4)
    root.left.right = TreeNode(5)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)

    print(check_if_binary_tree_is_perfect(root))
