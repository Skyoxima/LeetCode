from typing import Optional

class ListNode:
  def __init__(self, val = 0, next = None) -> None:
    self.val = val
    self.next = next

class Solution:
  def addTwoNumbers(self, l1: ListNode|None, l2: ListNode|None) -> ListNode:
    l1_str, l2_str = "", ""
    
    while(l1 != None):
      l1_str = str(l1.val) + l1_str
      l1 = l1.next
    
    while(l2 != None):
      l2_str = str(l2.val) + l2_str
      l2 = l2.next
    ans_list = [int(i) for i in str(int(l1_str) + int(l2_str))]
    ans_list.reverse()
    
    ans = ListNode()
    p = ans
    for ix in range(len(ans_list) - 1):
      p.val = ans_list[ix]
      p.next = ListNode()
      p = p.next
    p.val = ans_list[-1]
    p.next = None

    return ans

def main():
  s = Solution()
  l1 = ListNode(2, ListNode(4, ListNode(3)))
  l2 = ListNode(5, ListNode(6, ListNode(4)))
  ans = s.addTwoNumbers(l1, l2)
  while(ans != None):
    print(ans.val, end=" ")
    ans = ans.next
main()