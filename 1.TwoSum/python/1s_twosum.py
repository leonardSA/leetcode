from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = []
        for i, locked in enumerate(nums):
            target_num = target - locked
            j = nums.index(target_num) if target_num in nums else -1
            if (i != j) and (j != -1):
                result.append(i)
                result.append(j)
                return result


def main():
    solution = Solution()
    result = solution.twoSum([2, 7, 11, 16], 27)
    print(result)


if __name__ == '__main__':
    main()
