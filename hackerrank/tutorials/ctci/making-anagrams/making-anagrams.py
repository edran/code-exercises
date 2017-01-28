from string import ascii_lowercase
import math

def get_args():
  a = raw_input().strip()
  b = raw_input().strip()
  return a, b

def count_letters(arr):
  container = {}
  # Need to have them all
  for c in ascii_lowercase:
    container[c] = 0

  for c in arr:
    container[c] += 1

  return container

def main():
  a, b = get_args()
  letters_a = count_letters(a)
  letters_b = count_letters(b)

  delta = 0
  for c in ascii_lowercase:
    delta += int(math.fabs(letters_a[c] - letters_b[c]))

  print delta

if __name__ == "__main__":
  main()
