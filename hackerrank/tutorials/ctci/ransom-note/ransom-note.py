#!/bin/env python

def get_args():
  raw_input()
  first = raw_input().strip().split()
  second = raw_input().strip().split()
  return first, second

def main_1():
  a, b = get_args()
  big_container = {}
  for word in a:
    if word not in big_container.keys():
      big_container[word] = 1
    else:
      big_container[word] += 1

  for word in b:
    if word not in big_container.keys() or big_container[word] == 0:
      print "No"
      return
    else:
      big_container[word] -= 1
  print "Yes"

from collections import defaultdict

def main_2():
  a, b = get_args()
  big_container = defaultdict(int)
  for word in a:
      big_container[word] += 1

  for word in b:
    if big_container[word] == 0:
      print "No"
      return
    else:
      big_container[word] -= 1
  print "Yes"

if __name__ == "__main__":
  main_2()
