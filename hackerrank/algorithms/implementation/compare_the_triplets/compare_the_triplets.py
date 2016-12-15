def parse_args():
    args = []
    args.append([int(x) for x in raw_input().strip().split(' ')])
    args.append([int(x) for x in raw_input().strip().split(' ')])
    return args

def main():
    alice = 0
    bob = 0
    a = parse_args()
    for i in range(len(a[0])):
        if a[0][i] > a[1][i]:
            alice += 1
        elif a[0][i] < a[1][i]:
            bob += 1
    print("%d %d" % (alice, bob))

if __name__ == "__main__":
  main()
