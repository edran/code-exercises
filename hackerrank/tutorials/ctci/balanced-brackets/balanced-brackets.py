def get_args():
  t = int(raw_input().strip())
  exps = []
  for a in xrange(t):
    exps.append(raw_input().strip())
  return exps

def is_matched(exp):
  stack = []
  combinations = {"[": "]",
                  "(": ")",
                  "{": "}"}

  if len(exp) % 2 == 1:
    return False

  for c in exp:
    if len(stack) == 0:
      if c in combinations.values():
        return False
      stack.append(c)
      continue
    if c in combinations.values():
      bracket = stack.pop()
      if c != combinations[bracket]:
        return False
    else:
      stack.append(c)

  return len(stack) == 0




def main():
  exps = get_args()
  for e in exps:
    if is_matched(e):
      print "YES"
    else:
      print "NO"

if __name__ == "__main__":
  main()
