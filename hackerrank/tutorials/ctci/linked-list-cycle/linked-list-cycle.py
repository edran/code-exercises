"""
Detect a cycle in a linked list. Note that the head pointer may be 'None' if the list is empty.

A Node is defined as:

    class Node(object):
        def __init__(self, data = None, next_node = None):
            self.data = data
            self.next = next_node
"""


# No need for defaultdict, as max length is 100
def has_cycle(head):
  seen = {}
  if not head:
    return False

  while head.next is not None:
    if head in seen.keys():
      return True

    seen[head] = True
    head = head.next

  return False
