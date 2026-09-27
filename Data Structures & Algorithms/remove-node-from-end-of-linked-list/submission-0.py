# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        count = 0
        counter = head
        while counter:
            counter = counter.next
            count += 1
        
        m = count-n+1

        
        if (m==1):
            return head.next

        start = head

        while (start and m>2):
            start = start.next
            m -=1 

        start.next = start.next.next

        return head