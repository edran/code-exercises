from itertools import combinations

def get_args():
  n, k = map(int, raw_input().strip().split(' '))
  a = map(int,raw_input().strip().split(' '))
  return [k, a]
def main():
  a = get_args()
  k = a[0]
  arr = a[1]
  counter = 0
  # I'm super lazy and can't be arsed writing two for loops
  for x, y in combinations(xrange(len(arr)), 2):
    if (arr[x] + arr[y]) % k == 0:
      counter += 1
  print(counter)

if __name__ == "__main__":
  main()
