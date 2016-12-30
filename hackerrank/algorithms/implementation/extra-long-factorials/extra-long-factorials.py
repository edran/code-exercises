def get_args():
  n = int(raw_input().strip())
  return n

def factorial(n):
  if n == 1:
    return 1
  else:
    return n * factorial(n - 1)

def main():
  n = get_args()
  print(factorial(n))

if __name__ == "__main__":
  main()
