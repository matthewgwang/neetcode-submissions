class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        values = set(nums)
        longest = 0

        for number in values:
            if number-1 not in values:
                length =1
                current = number

                while current + 1 in values:
                    current += 1
                    length += 1
                
                longest = max(longest, length)
        return longest