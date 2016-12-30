def get_args():
  raw_input()
  l = map(int, raw_input().strip().split(" "))
  return l

def isortprint(l):
  unsorted = l[-1]
  flag = False
  for i in range(len(l) - 1):
    # we start from second last
    if l[-(i + 2)] > unsorted:
      l[-(i + 1)] = l[-(i + 2)]
      print(" ".join(map(str, l)))
    else:
      l[-(i + 1)] = unsorted
      print(" ".join(map(str, l)))
      flag = True
      break
  if not flag:
    l[0] = unsorted
    print(" ".join(map(str, l)))

def main():
  a = get_args()
  isortprint(a)
  pass

if __name__ == "__main__":
  main()
