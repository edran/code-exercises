import bisect


def get_args():
  n = int(raw_input().strip())
  a = []
  for i in xrange(n):
    a_t = int(raw_input().strip())
    a.append(a_t)
  return a


def running_median_bisect(n):
  last_elem = n.pop()
  bisect.insort(n, last_elem)

  if len(n) % 2 == 1:
    median = float(n[len(n) / 2])
  else:
    index = len(n) / 2
    median = float(float((n[index - 1]) + n[index]) / 2)

  return median, n


def running_median_naive(l):
  median = 0
  n = sorted(l)

  if len(n) % 2 == 1:
    median = float(n[len(n) / 2])
  else:
    index = len(n) / 2
    median = float(float((n[index - 1]) + n[index]) / 2)

  return median, n


def running_median(l):
  return running_median_bisect(l)
  # return running_median_naive(l)


def main():
  a = get_args()
  l = []
  for n in a:
    l.append(n)
    median, l = running_median(l)
    print("%.1f" % median)

if __name__ == "__main__":
  main()
