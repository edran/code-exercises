class Solution:
    # @param A : list of list of integers
    # @return the same list modified
    def rotate(self, A):
        for i in range(len(A)):
            self.rotate_outer(A, i, len(A) - (i * 2) - 1)
        return A

    # length is useless, since we know pos and len(A)
    def rotate_outer(self, A, pos, length):
        if len(A) % 2 == 0 and length == 0:
            return
        if len(A) % 2 == 1 and length == 1:
            return

        for i in range(length):
            tl = A[pos][pos + i]
            tr = A[pos + i][pos + length]
            br = A[pos + length][pos + length - i]
            bl = A[pos + length - i][pos]
            # swap
            A[pos][pos + i] = bl
            A[pos + i][pos + length] = tl
            A[pos + length][pos + length - i] = tr
            A[pos + length - i][pos] = br


if __name__ == "__main__":
    s = Solution()
    A = [
        [1, 2],
        [3, 4],
    ]
    A = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
    ]
    A = [
        [31, 32, 228, 333],
        [79, 197, 241, 246],
        [77, 84, 126, 337],
        [110, 291, 356, 371]]
    print(s.rotate(A))
