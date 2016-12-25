
def get_args():
  s,t = raw_input().strip().split(' ')
  s,t = [int(s),int(t)]
  a,b = raw_input().strip().split(' ')
  a,b = [int(a),int(b)]
  m,n = raw_input().strip().split(' ')
  m,n = [int(m),int(n)]
  apple = map(int,raw_input().strip().split(' '))
  orange = map(int,raw_input().strip().split(' '))
  return [[s, t], [a, b], [apple, orange]]

def main():
  a = get_args()
  sam = a[0]
  a_tree = a[1][0]
  o_tree = a[1][1]
  apples = a[2][0]
  oranges = a[2][1]
  acount = 0
  ocount = 0
  for i in apples:
    pos = a_tree + i
    if pos >= sam[0] and pos <= sam[1]:
      acount += 1
  for i in oranges:
    pos = o_tree + i
    if pos >= sam[0] and pos <= sam[1]:
      ocount += 1
  print(acount)
  print(ocount)

if __name__ == "__main__":
  main()
