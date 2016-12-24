from string import ascii_lowercase

def get_args():
  h = map(int,raw_input().strip().split(' '))
  word = raw_input().strip()
  return [h, word]

def main():
  a = get_args()
  h = a[0]
  word = a[1]
  highest = 0
  for c in word:
    ch = h[ascii_lowercase.index(c)]
    if highest < ch:
      highest = ch
  print(len(word) * highest)

if __name__ == "__main__":
  main()
