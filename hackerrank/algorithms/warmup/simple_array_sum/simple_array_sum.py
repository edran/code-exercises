
def get_args():
  n = int(raw_input().strip())
  arr = map(int,raw_input().strip().split(' '))
  return arr

def main():
  a = get_args()
  print(sum(a))

if __name__ == "__main__":
  main()
