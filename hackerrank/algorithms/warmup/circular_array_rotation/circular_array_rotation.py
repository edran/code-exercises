from collections import deque

def get_args():
  param = [int(x) for x in raw_input().strip().split(' ')]
  k = param[1]
  q = param[2]
  arr = map(int,raw_input().strip().split(' '))
  arr2 = []
  for a0 in xrange(q):
    arr2.append(int(raw_input().strip()))
  return [arr, arr2, k]

# too slow!
def right_circ(arr):
  last = arr.pop()
  return [last] + arr

def main():
  a = get_args()
  arr = a[0]
  indices = a[1]
  # for i in xrange(a[2]):
  #   arr = right_circ(arr)
  arr = deque(arr)
  arr.rotate(a[2])
  for i in indices:
    print(arr[i])
  pass

if __name__ == "__main__":
  main()
