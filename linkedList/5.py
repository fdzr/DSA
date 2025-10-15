from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def print_linkedlist(head: Optional[ListNode]):
    while head != None:
        print(head.val, end=" ")
        head = head.next


def removeNthFromEnd(head: Optional[ListNode], n: int) -> Optional[ListNode]:
    aux = None
    temp = head
    prev = head

    while n > 0:
        temp = temp.next
        n -= 1

    if temp is None:
        return head.next

    while temp is not None:
        aux = prev
        prev = prev.next
        temp = temp.next

    aux.next = prev.next

    return head


head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
head.next.next.next = ListNode(4)
head.next.next.next.next = ListNode(5)


a = removeNthFromEnd(head, 5)
print_linkedlist(a)
