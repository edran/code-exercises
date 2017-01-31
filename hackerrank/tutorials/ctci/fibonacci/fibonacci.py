def get_args():
  n = int(raw_input())
  return n

memory = {}
def fibonacci_memo(n):
  if n < 2:
    return n
  if n not in memory.keys():
    memory[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2)
  return memory[n]

def fibonacci(n):
  # Write your code here.
  if n == 0:
    return 0
  if n == 1:
    return 1
  return fibonacci(n-1) + fibonacci(n-2)


def main():
  a = get_args()
  print(fibonacci_memo(a))

if __name__ == "__main__":
  main()
