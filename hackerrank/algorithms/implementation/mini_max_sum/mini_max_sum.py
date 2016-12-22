
def get_args():
  arr = map(int, raw_input().strip().split(" "))
  return arr

def main():
  arr = get_args()
  arr = sorted(arr)
  print(sum(arr[:4])),
  print(sum(arr[1:]))

if __name__ == "__main__":
  main()
