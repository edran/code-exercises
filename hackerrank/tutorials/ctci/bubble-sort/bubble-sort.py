def get_args():
    int(input().strip())
    a = list(map(int, input().strip().split(' ')))
    return a


def bubble_sort(array):
    total_swaps = 0
    for i in range(len(array)):
        swaps = 0
        for j in range(len(array) - 1):
            if array[j] > array[j+1]:
                tmp = array[j+1]
                array[j+1] = array[j]
                array[j] = tmp
                swaps += 1
        total_swaps += swaps
        if swaps < 1:
            break

    print("Array is sorted in {} swaps.".format(total_swaps))
    print("First Element: {}".format(array[0]))
    print("Last Element: {}".format(array[-1]))
    return array


def main():
    a = get_args()
    bubble_sort(a)

if __name__ == "__main__":
    main()
