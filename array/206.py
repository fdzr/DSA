from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def swapPairs(head: Optional[ListNode]) -> Optional[ListNode]:
    if head is None or head.next is None:
        return head

    dummy = ListNode(-1)
    dummy.next = head

    current = dummy

    while current.next is not None:
        first_node = current.next
        second_node = current.next.next

        if first_node.next is None:
            break

        first_node.next = second_node.next
        second_node.next = first_node

        current.next = second_node
        current = current.next
        current = current.next

    return dummy.next
