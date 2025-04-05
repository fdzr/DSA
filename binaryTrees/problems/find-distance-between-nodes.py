from typing import List


class Node:
    def __init__(self, key: int):
        self.key: int = key
        self.left: Node = None
        self.right: Node = None


def lowest_common_ancestor(
    root: Node,
    node1: int,
    node2: int,
):
    if root is None:
        return None

    if root.key in [node1, node2]:
        return root

    ans_l = lowest_common_ancestor(root.left, node1, node2)
    ans_r = lowest_common_ancestor(root.right, node1, node2)

    if ans_l is not None and ans_r is not None:
        return root

    return ans_l if ans_l is not None else ans_r


def get_distance_from_root(
    root: Node,
    node: int,
    level: int,
    sol: List[int],
):
    if root is None:
        return False

    if root.key == node:
        sol[0] = level
        return True

    if get_distance_from_root(
        root.left,
        node,
        level + 1,
        sol,
    ):
        return True

    if (
        get_distance_from_root(
            root.right,
            node,
            level + 1,
            sol,
        )
        is True
    ):
        return True

    return False


def find_distance_between_nodes(
    root: Node,
    node1: int,
    node2: int,
):
    distance1, distance2 = [-1], [-1]

    get_distance_from_root(root, node1, 0, distance1)
    get_distance_from_root(root, node2, 0, distance2)

    if distance1[0] == -1 or distance2[0] == -1:
        return -1
    distance_to_lca = [-1]

    lca = lowest_common_ancestor(
        root,
        node1,
        node2,
    )

    get_distance_from_root(
        root,
        lca.key,
        0,
        distance_to_lca,
    )

    return distance1[0] + distance2[0] - 2 * distance_to_lca[0]


if __name__ == "__main__":
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)

    root.left.right = Node(4)

    root.right.left = Node(5)
    root.right.right = Node(6)

    root.right.left.left = Node(7)
    root.right.left.right = Node(8)

    print(find_distance_between_nodes(root, 7, 1))
