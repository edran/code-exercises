def get_args():
  x1,v1,x2,v2 = raw_input().strip().split(' ')
  x1,v1,x2,v2 = [int(x1),int(v1),int(x2),int(v2)]
  return [x1, v1, x2, v2]

def main():
  a = get_args()
  x1 = a[0]
  v1 = a[1]
  x2 = a[2]
  v2 = a[3]

  # handle simple cases
  if (x1 > x2 and v1 > v2) or (x2 > x1 and v2 > v1):
    print("NO")
    return

  counter1 = x1
  counter2 = x2

  # could also do (x1 - x2) % (v2 - v1) == 0
  for i in range(10000):
    counter1 += v1
    counter2 += v2
    if counter1 == counter2:
      print("YES")
      return

  print("NO")
  return

if __name__ == "__main__":
  main()
