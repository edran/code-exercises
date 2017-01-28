""" Node is defined as
class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
"""

# It could be that leaves(leaves(values)) do not match property, so we need to
# set boundaries
def bound_check(root, min_value, max_value):
  if root is None:
    return True

  if root.data >= max_value or root.data <= min_value:
    return False

  return (bound_check(root.left, min_value, root.data)
          and bound_check(root.right, root.data, max_value))

def check_binary_search_tree_(root):
  return bound_check(root, -1, 10000)
