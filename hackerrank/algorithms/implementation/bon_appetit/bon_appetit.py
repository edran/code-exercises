def get_args():
  meta = [int(x) for x in raw_input().strip().split(" ")]
  arr = [int(x) for x in raw_input().strip().split(" ")]
  charged = int(raw_input())
  return [meta[1], arr, charged]

def main():
  a = get_args()
  k = a[0]
  arr = a[1]
  charged = a[2]

  arr.pop(k)
  total = sum(arr) / 2

  diff = charged - total
  if diff == 0:
    print("Bon Appetit")
  else:
    print(diff)

if __name__ == "__main__":
  main()
