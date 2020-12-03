from typing import List


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        uglies = [1]
        i2 = i3 = i5 = 0
        mul_2 = 2
        mul_3 = 3
        mul_5 = 5
        next_ugly = 1
        for i in range(1, n):
            next_ugly = min(mul_2, mul_3, mul_5)
            uglies.append(next_ugly)

            if next_ugly == mul_2:
                i2 = i2 + 1
                mul_2 = uglies[i2] * 2

            if next_ugly == mul_3:
                i3 = i3 + 1
                mul_3 = uglies[i3] * 3

            if next_ugly == mul_5:
                i5 = i5 + 1
                mul_5 = uglies[i5] * 5

        return next_ugly


def main():
    s = Solution()
    print(s.nthUglyNumber(10))
    print(s.nthUglyNumber(11))
    print(s.nthUglyNumber(12))
    print(s.nthUglyNumber(13))


if __name__ == "__main__":
    main()
