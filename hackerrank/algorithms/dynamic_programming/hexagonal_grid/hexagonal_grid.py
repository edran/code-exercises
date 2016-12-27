def get_args():
  tests = int(raw_input().strip())
  l = []
  for i in range(tests):
    n = raw_input()
    t = []
    t.append(raw_input())
    t.append(raw_input())
    l.append(t)
  return l

def hexagrid(grid):
  total = sum(map(int, grid[0])) + sum(map(int, grid[1]))
  if total % 2 == 1:
    return "NO"
  # technically correct, but problem could have been formulated better
  if total == 2 * len(grid[0]):
    return "YES"
  free_cells = 0
  for i in range(len(grid[0])):
    free_cells += 1 - int(grid[0][i])
    if ((grid[0][i] == "1" and grid[1][i] == "1")
        or (i > 0 and grid[0][i] == "1" and grid[1][i - 1] == "1")):
      # we have found a blocked column
      if free_cells % 2 == 1:
        return "NO"
    free_cells += 1 - int(grid[1][i])
  return "YES"
def main():
  a = get_args()
  for t in a:
    print(hexagrid(t))
  pass

if __name__ == "__main__":
  main()
