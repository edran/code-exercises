class Node(object):
  # first one is 1
  def __init__(self):
    self.data = None
    self.children = []

  def add_leaf(self, root, node):
    # print("Data %d - root %d" % (self.data, root))
    if self.data == root:
      self.children.append(node)
      return True

    for child in self.children:
      if child.add_leaf(root, node):
        return True
    return False

  def __repr__(self, level=0):
    ret = "\t"*level+repr(self.data)+"\n"
    for child in self.children:
      ret += child.__repr__(level+1)
    return ret

def get_args():
  n, m = map(int, raw_input().strip().split(" "))
  tree = Node()
  tree.data = 1
  for i in range(m):
    leaf, root = map(int, raw_input().strip().split(" "))
    node = Node()
    node.data = leaf
    tree.add_leaf(root, node)
  return tree

def decompose(tree, roots=[]):
  # dfs
  total_value = 1
  for child in tree.children:
    can_root, value, roots = decompose(child, roots)
    if can_root:
      roots.append(child.data)
    else:
      total_value += value

  can_root = total_value % 2 == 0
  return can_root, total_value, roots



def main():
  tree = get_args()
  # print(tree)
  _, _, roots = decompose(tree)
  # print(roots)
  print(len(roots))

if __name__ == "__main__":
  main()
