from collections import deque

def get_args():
  n, k = map(int, raw_input().strip().split(' '))
  a = map(int, raw_input().strip().split(' '))
  return [a, k]

def array_rotate(arr, k):
  d = deque(arr)
  d.rotate(-k)
  return list(d)

def main():
  a = get_args()
  arr = a[0]
  k = a[1]
  answer = array_rotate(arr, k)
  print ' '.join(map(str,answer))
  pass

if __name__ == "__main__":
  main()
