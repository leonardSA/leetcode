from typing import List


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0
        length = 0
        max_length = 0
        seen = {}
        while i < len(s):
            if s[i] in seen:
                max_length = max(length, max_length)
                length = 0
                i = seen[s[i]] + 1
                seen.clear()
            seen[s[i]] = i
            length = length + 1
            i = i + 1
        return max(length, max_length)


def main():
    solution = Solution()
    result = solution.lengthOfLongestSubstring("pwwkew")
    print(result)


if __name__ == '__main__':
    main()
