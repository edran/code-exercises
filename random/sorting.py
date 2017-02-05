#!/usr/bin/env python3
import random


class SortTester:

    def __init__(self, min_n, max_n):
        self.max_n = max_n
        self.min_n = min_n

    def gen_random_array(self, array_length):
        array = []
        for i in range(array_length):
            array.append(random.randint(self.min_n, self.max_n))
        return array

    def test_sort(self, sort_algo, array_length):
        array = self.gen_random_array(array_length)
        ground_truth = sorted(array)
        outcome = sort_algo(array)

        # check arrays
        assert(len(ground_truth) == len(outcome))
        for i in range(len(ground_truth)):
            if ground_truth[i] != outcome[i]:
                return False
        return True


def bubble_sort(array):
    for i in range(len(array)):
        swaps = 0
        for j in range(len(array) - 1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
                swaps += 1
        if swaps == 0:
            break
    return array


def merge_sort(array):
    return array


def run_some_test(number_tests, max_array_length, sort_algo):
    t = SortTester(0, 2000)
    print("Testing {}...".format(sort_algo.__name__), end="")

    for i in range(number_tests):
        length = random.randint(1, max_array_length)
        print("{} ".format(t.test_sort(sort_algo, length)), end="")
    print("")


if __name__ == "__main__":
    run_some_test(10, 1000, bubble_sort)
