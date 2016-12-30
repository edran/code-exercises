def get_args():
  k = int(raw_input().strip())
  raw_input()
  l = map(int, raw_input().strip().split(" "))
  return k, l

def main():
  k, l = get_args()
  print(l.index(k))
  pass

if __name__ == "__main__":
  main()
