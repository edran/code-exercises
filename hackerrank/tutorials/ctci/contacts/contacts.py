from string import ascii_lowercase
from collections import defaultdict


class Trie(object):
  __slots__ = ['leaves', 'counter']

  def __init__(self):
    self.leaves = defaultdict(Trie)
    self.counter = 0

  def add_word(self, word):
    node = self
    for c in word:
      node = node.leaves[c]
      node.counter += 1

  def count_words(self, prefix):
    node = self
    for c in prefix:
      if c not in node.leaves:
        return 0
      node = node.leaves[c]
    return node.counter


class ContactBook(object):
  def __init__(self):
    self.book = Trie()

  def add(self, contact):
    self.book.add_word(contact)

  def find(self, query):
    "Print number of words starting with query"
    return self.book.count_words(query)

  def do_operation(self, op, value):
    if op == "add":
      self.add(value)
    elif op == "find":
      print(self.find(value))


def get_args():
  n = int(raw_input().strip())
  ops = []
  contacts = []
  for a0 in xrange(n):
    op, contact = raw_input().strip().split(' ')
    ops.append(op)
    contacts.append(contact)
  return ops, contacts

def main():
  ops, contacts = get_args()
  cb = ContactBook()
  for i in range(len(ops)):
    cb.do_operation(ops[i], contacts[i])

if __name__ == "__main__":
  main()
