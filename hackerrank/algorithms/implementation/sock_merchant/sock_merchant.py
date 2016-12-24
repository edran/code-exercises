def get_args():
  n = int(raw_input().strip())
  c = map(int,raw_input().strip().split(' '))
  return c

def main():
  a = get_args()
  a.sort()
  pairs = 0
  previous = None
  temp_counter = 0
  for i in a:
    if i != previous:
      pairs += int(temp_counter / 2)
      temp_counter = 0
    temp_counter += 1
    previous = i
  pairs += int(temp_counter / 2)
  print(pairs)


if __name__ == "__main__":
  main()
