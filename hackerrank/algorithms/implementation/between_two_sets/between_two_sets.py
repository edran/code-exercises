def get_args():
  n,m = raw_input().strip().split(' ')
  n,m = [int(n),int(m)]
  a = map(int,raw_input().strip().split(' '))
  b = map(int,raw_input().strip().split(' '))
  return [a, b]

def a_check(A, e):
  for a in A:
    if e % a != 0:
      return False
  return True

def b_check(B, e):
  for b in B:
    if b % e != 0:
      return False
  return True

def main():
  a = get_args()
  A = a[0]
  B = a[1]
  start = max(A)
  end = min(B)
  counter = 0
  for i in range(start, end+1):
    if a_check(A, i) and b_check(B, i):
      counter += 1
  print(counter)
  pass

if __name__ == "__main__":
  main()
