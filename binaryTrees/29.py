from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None) -> None:
        self.val = val
        self.left = left
        self.right = right


class FindElements:
    def __init__(self, root: Optional[TreeNode]) -> None:
        self.root = root
        self.nums = []
        self.recover_tree()

    def find(self, target: int) -> bool:
        return self.find_aux(self.root, target)

    def find_aux(self, tree: Optional[TreeNode], target):
        if tree is None:
            return False

        if tree.val == target:
            return True

        return self.find_aux(tree.left, target) or self.find_aux(tree.right, target)

    def recover_tree(self) -> Optional[TreeNode]:
        self.root.val = 0
        queue = [self.root]

        while queue:
            node = queue.pop(0)

            if node.left is not None:
                queue.append(node.left)
                node.left.val = node.val * 2 + 1
            if node.right is not None:
                queue.append(node.right)
                node.right.val = node.val * 2 + 2


def pre_order(tree: Optional[TreeNode]):
    if tree is None:
        return

    print(tree.val)
    pre_order(tree.left)
    pre_order(tree.right)


if __name__ == "__main__":
    root = TreeNode(val=-1)
    root.left = TreeNode(val=-1)
    root.right = TreeNode(val=-1)

    root.left.left = TreeNode(val=-1)
    root.left.right = TreeNode(val=-1)

    obj = FindElements(root)
    print(obj.find(1))
    print(obj.find(4))
