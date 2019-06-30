from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        nums_table = {}
        for i, n in enumerate(nums):
            nums_table[n] = i
        for i, n in enumerate(nums):
            complement = target - n
            j = nums_table.get(complement, None)
            if j and j != i:
                return [i, j]
        return None


def main():
    solution = Solution()
    result = solution.twoSum([2, 7, 11, 16], 27)
    print(result)


if __name__ == '__main__':
    main()
