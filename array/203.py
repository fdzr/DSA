from typing import List, Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def print_list(l: Optional[ListNode]):
    while l is not None:
        print(l.val)
        l = l.next


def mergeTwoLists(
    list1: Optional[ListNode],
    list2: Optional[ListNode],
) -> Optional[ListNode]:

    temp = ListNode(-1)
    answer = temp

    while list1 or list2:
        temp.next = ListNode(-1)
        temp = temp.next

        if list1 is not None and list2 is None:
            temp.val = list1.val
            list1 = list1.next
        elif list2 is not None and list1 is None:
            temp.val = list2.val
            list2 = list2.next

        if list1 is not None and list2 is not None:
            if list1.val <= list2.val:
                temp.val = list1.val
                list1 = list1.next
            else:
                temp.val = list2.val
                list2 = list2.next

    return answer.next


list1 = ListNode(1)
list1.next = ListNode(2)
list1.next.next = ListNode(4)
list2 = ListNode(1)
list2.next = ListNode(3)
list2.next.next = ListNode(4)
print(print_list(mergeTwoLists(list1, list2)))
