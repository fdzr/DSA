from typing import Optional
from collections import deque
import heapq


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def kthLargestLevelSum(root: Optional[TreeNode], k: int) -> int:
    q = deque([root])
    top_sums = []

    while q:
        sum = 0

        for i in range(len(q)):
            node = q.popleft()
            sum += node.val

            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)

        heapq.heappush(top_sums, sum)

        if len(top_sums) > k:
            heapq.heappop(top_sums)

    if len(top_sums) < k:
        return -1

    return heapq.heappop(top_sums)


root = TreeNode(5)
root.left = TreeNode(8)
root.right = TreeNode(9)

root.left.left = TreeNode(2)
root.left.right = TreeNode(1)

root.right.left = TreeNode(3)
root.right.right = TreeNode(7)

root.left.left.left = TreeNode(4)
root.left.left.right = TreeNode(6)

print(kthLargestLevelSum(root, 2))


root = TreeNode(1)
root.left = TreeNode(2)
root.left.left = TreeNode(3)

print(kthLargestLevelSum(root, 1))
