def get_args():
  m = input()
  ar = [int(i) for i in raw_input().strip().split()]
  return ar

def my_sort(ar):
  ar.reverse()
  unsorted = ar[0]
  flag = False
  for i in range(len(ar) - 1):
    if unsorted < ar[i + 1]:
      ar[i] = ar[i+1]
    else:
      ar[i] = unsorted
      flag = True
  if not flag:
    ar[-1] = unsorted
  ar.reverse()
  return ar

def insertsort(ar, i=1, dumb=False):
  if i == len(ar):
    return
  if dumb:
    ar = my_sort(ar[:i+1]) + ar[i+1:]
  else:
    ar = sorted(ar[:i+1]) + ar[i+1:]
  print(" ".join(map(str, ar)))
  return insertsort(ar, i+1)

def main():
  a = get_args()
  insertsort(a, dumb=True)
  pass

if __name__ == "__main__":
  main()
